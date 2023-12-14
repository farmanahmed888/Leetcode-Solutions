class Solution {
public:
    bool helper(int start,vector<vector<int>>&graph){
        int n=graph.size();
       vector<int>color(n,-1);
       int c=1;
       queue<int>q;
       q.push(start);
       color[start]=c;
       while(!q.empty()){
           int x=q.front();q.pop();
           for(auto it:graph[x]){
               if(color[it]==-1){
                   color[it]=1-color[x];
                   q.push(it);
               }else if(color[it]==color[x]) return false;
           }
       }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       for(int i=0;i<n;i++){
           if(!helper(i,graph)){
               return false;
           }
       }
       return true;
    }
};