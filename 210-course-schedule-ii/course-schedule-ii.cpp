class Solution {
public:
    bool cyclic(int node,vector<bool>&visited,vector<bool>&pathVisited,vector<int>adj[]){
        visited[node]=true;
        pathVisited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(cyclic(it,visited,pathVisited,adj)==true) return true;
            }
            else if(pathVisited[it]==true) return true;
        }
        pathVisited[node]=false;
        return false;
    }
    void dfs(int node,vector<int>&ans,vector<bool>&vis,vector<int>adj[]){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,ans,vis,adj);
            }
        }
        ans.push_back(node);
    }
    vector<int> findOrder(int V, vector<vector<int>>& P) {
        vector<int>ans;
        vector<bool>vis(V,false);
        vector<int>adj[V];
        for(auto it:P){
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visited(V,false);
        vector<bool>pathVisited(V,false);
        for(int i=0;i<V;i++){
            if(cyclic(i,visited,pathVisited,adj)) return {};
        }
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,ans,vis,adj);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};