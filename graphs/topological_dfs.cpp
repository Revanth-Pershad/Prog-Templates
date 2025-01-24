void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited){
        visited[node] = true;
        for(int ngh : adj[node])
            if(!visited[ngh])dfs(ngh, adj, st, visited);
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        stack<int> st;
        int n = adj.size();
        
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i])dfs(i, adj, st, visited);
        }
        
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
