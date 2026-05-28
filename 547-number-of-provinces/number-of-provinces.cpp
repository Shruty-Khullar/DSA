class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node){
        visited[node]=1;
        for(auto itr: adj[node]){
            if(!visited[itr])
                dfs(adj,visited,itr);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        vector<vector<int>> adj(nodes);
        for(int i=0;i<nodes;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(nodes);
        int numProv = 0;
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                numProv++;
                dfs(adj,visited,i);
            }
        }
        return numProv;
    }
};