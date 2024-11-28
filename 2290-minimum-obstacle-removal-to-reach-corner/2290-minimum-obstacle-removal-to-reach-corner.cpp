class Solution {
public:
    int D[5]={-1,0, 1,0, -1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, 0});
        grid[0][0]=-1;
        while(pq.size()){
            auto top=pq.top();
            pq.pop();
            if(top[1]==m-1 and top[2]==n-1)return top[0];
            for(int k=0; k<4; k++){
                int x=top[1]+D[k], y=top[2]+D[k+1];
                if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==-1)continue;
                pq.push({top[0]+grid[x][y], x, y});
                grid[x][y]=-1;
            }
        }
        return -1;
    }
};