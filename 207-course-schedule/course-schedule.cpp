class Solution {
public:
    bool cycle(int node,vector<bool>&vis,vector<bool>&pathVis,vector<int>adj[]){
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,pathVis,adj)==true) return true;
            }else if(pathVis[it]==true) return true;
        }
        pathVis[node]=false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& arr) {
        vector<int>adj[V];
        vector<bool>vis(V,false);
        vector<bool>pathVis(V,false);
        for(auto it:arr){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            if(cycle(i,vis,pathVis,adj)==true) return false;
        }
        return true;
    }
};