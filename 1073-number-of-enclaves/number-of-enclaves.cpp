class Solution {
public:
    void dfs(int r,int c,int m,int n,vector<vector<int>>&grid){
        if(r<0 or r>=m or c<0 or c>=n or grid[r][c]==0) return;
        grid[r][c]=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            dfs(nrow,ncol,m,n,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(i,0,m,n,grid);
            if(grid[i][n-1]==1)dfs(i,n-1,m,n,grid);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)dfs(0,j,m,n,grid);
            if(grid[m-1][j]==1)dfs(m-1,j,m,n,grid);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};