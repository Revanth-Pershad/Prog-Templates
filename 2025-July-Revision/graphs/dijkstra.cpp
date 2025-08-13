#include <bits/stdc++.h>

using namespace std;

int dijkstra(int start, int end, vector<vector<pair<int, int>>> &graph){
    vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int node = pq.top().second, dt = pq.top().first;
        pq.pop();

        if(node == end)return dist[end];

        for(auto x : graph[node]){
            int ng = x.second, wt = x.first;

            if(dist[ng] > dt + wt){
                dist[ng] = dt + wt;
                pq.push({dist[ng], ng});
            }
        }
    }
    return -1;
}

int main(){

}