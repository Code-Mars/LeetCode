class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), D[5]={-1, 0, 1, 0, -1};
        if(grid[0][1]>1 and grid[1][0]>1)return -1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, 0});
        while(pq.size()){
            auto d=pq.top()[0], i=pq.top()[1], j=pq.top()[2];
            pq.pop();
            if(i==m-1 and j==n-1)return d;
            if(grid[i][j]==-1)continue;
            grid[i][j]=-1;
            for(int k=0; k<4; k++){
                int x=i+D[k], y=j+D[k+1];
                if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==-1)continue;
                if(grid[x][y]<=d+1)pq.push({d+1,x, y});
                else pq.push({grid[x][y]+((grid[x][y]-d)%2==0), x, y});
            }
        }
        return -1;
    }
};