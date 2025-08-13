// Walk - A random traversal of graph Eg: (A to B to C to A to C) 
// Trail - A walk in which edges cannot be repeated but Vertices can be
// Euler Circuit - A trail in which the start and the end is the same vertice and covers all the edges
// Eulerican Path - Path that visits every edge in a graph exactly once. The starting and ending points of an Eulerian path are different vertices. 

// 1. Undirected Graph
// Eulerian Circuit (Cycle):

// Every vertex has an even degree.
// Eulerian Path:

// Either all vertices have even degree (which means it is an Eulerian circuit) OR
// Exactly two vertices have odd degree.

// 2. Directed Graph
// Eulerian Circuit (Cycle):

// Every vertex has equal in-degree and out-degree.
// Eulerian Path:

// At most one vertex has (out-degree) - (in-degree) = 1.
// At most one vertex has (in-degree) - (out-degree) = 1.
// All other vertices have equal in-degree and out-degree.

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &res, vector<int> &out, vector<vector<int>> &graph){
    // We can use the current count of the out vector as an index
    // to see which next edge we want to use, as we donot use a 
    // Visited Array to check if we visited a node as the out count
    // is equal to the  number of edges that a node has
    
    while(out[node]){
        out[node]--;
        dfs(graph[node][out[node]], res, out, graph);
    }
    res.push_back(node);
}

bool possible(vector<int> &out, vector<int> &in){
    // Check from how many nodes can we start our eulerian path
    int possStarts = 0, possEnds = 0;
    for(int i = 0; i < out.size(); i++){
        // Out edge is greater by 1 as we leave
        if(out[i] - in[i] == 1)
            possStarts++;
        // In edge is greater by 1 as we enter
        else if(in[i] - out[i] == 1)
            possEnds++;
        // If a node has uneven out or in then that means
        // we cannot enter or leave the node after one traversal
        // Thus returning false
        else if(abs(out[i] - in[i]) > 1)
            return false;
    }
    // Start and end Nodes are Same (we can start from any node)
    if(possEnds == 0 && possStarts == 0)
        return true;
    // We have one possible start
    if(possEnds == 1 && possStarts == 1)
        return true;
    // Multiple starts means traversal is not possible
    return false;
}

int startNode(vector<int> &out, vector<int> &in){
    for(int i = 0; i < out.size(); i++)
        if(out[i] - in[i] == 1)
            return i;
    
    return 0; // Any node is possible
}


vector<int> eul_pat(vector<vector<int>> &graph, int n, int edges){
    vector<int> out_edges(n, 0), in_edges(n, 0);
    for(int i = 0; i < n; i++){
        for(int x : graph[i]){
            out_edges[i]++;
            in_edges[x]++;
        }
    }
    
    // Verify if possible
    if(!possible(out_edges, in_edges))
        return {};
    
    // Get the Start edge
    int start = startNode(out_edges, in_edges);
    
    // Start the dfs with out_edges
    vector<int> res;
    dfs(start, res, out_edges, graph);
    
    // As we are pushing back in the array instead of start
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n, edges;
    cin >> n >> edges;
    vector<vector<int>> graph(n);
    for(int i = 0; i < edges; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    
    vector<int> eulerian_path = eul_pat(graph, n, edges);
    for(int x : eulerian_path)
        cout << x << " ";
        
    cout << endl;
}

