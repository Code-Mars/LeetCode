class Solution {
public:
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> XobSet, YobSet;
        XobSet.reserve(10000), YobSet.reserve(10000);
        for(auto& ob: obstacles){
            int x=ob[0], y=ob[1];
            XobSet[x].insert(y);
            YobSet[y].insert(x);
        }

        const int dir[4][2]={{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x=0, y=0, dx=0, dy=1, face=0, maxD2=0;
        for(int c: commands){
            switch(c){
                case -2: face=(face+1)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                case -1: face=(face+3)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                default:
                //    cout<<"\nc="<<c<<" face="<<face<<":";
                    switch(face){
                        case 0: {//up
                            auto it=upper_bound(XobSet[x].begin(), XobSet[x].end(), y);
                            if (it!=XobSet[x].end() && *it<=y+c) y=*it-1;
                            else y+=c;
                            break;
                        }
                        case 1: {//left
                            auto it=upper_bound(YobSet[y].rbegin(), YobSet[y].rend(), x, greater<>());
                            if (it!=YobSet[y].rend() && *it>=x-c) x=*it+1;
                            else x-=c;
                            break;
                        }
                        case 2: {//down
                            auto it=upper_bound(XobSet[x].rbegin(), XobSet[x].rend(), y, greater<>());
                            if (it!=XobSet[x].rend() && *it>=y-c) y=*it+1;
                            else y-=c;
                            break;
                        }
                        case 3: {//right
                            auto it=upper_bound(YobSet[y].begin(), YobSet[y].end(), x);
                            if (it!=YobSet[y].end() && *it<=x+c) x=*it-1;
                            else x+=c;
                            break;
                        }
                    }
                //    cout<<"("<<x<<","<<y<<"),";
                    maxD2=max(maxD2, x*x+y*y);
                }
        }
        return maxD2;
    }
};