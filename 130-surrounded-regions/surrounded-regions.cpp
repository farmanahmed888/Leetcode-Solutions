class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        if(i<0 or i>=m or j<0 or j>=n or board[i][j]!='O') return;
        board[i][j]='#';
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+r[k];
            int ncol=j+c[k];
            dfs(nrow,ncol,m,n,board);
        }

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,m,n,board);
            if(board[i][n-1]=='O')dfs(i,n-1,m,n,board);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0,j,m,n,board);
            if(board[m-1][j]=='O') dfs(m-1,j,m,n,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};