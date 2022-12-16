#include <bits/stdc++.h>

using namespace std;

string spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    string mst = "";
    priority_queue<
        vector<int>,
        vector<vector<int>>, greater<vector<int>>> pq;
    
    vector<int> vis(V, 0);
    
    pq.push({0,0,0});
    int sum = 0;
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it[1];
        int w = it[0];
        int dest = it[2];
        
        if (!vis[node]) {
            vis[node] = 1;
            sum += w;
            mst += "("+to_string(dest)+", "+to_string(node)+", "+to_string(w)+") -> ";
            for (auto itp: adj[node]) {
                int n = itp[0];
                int ed = itp[1];
                if (!vis[n]) {
                    pq.push({ed, n, node});
                }
            }
            
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout<< "Vertices followed by Edges: \n";
    cin>>V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E) {
        int source, dest, w;
        cin >> source >> dest >> w;

        //Undirected graph
        adj[source].push_back({dest, w});
        adj[dest].push_back({source, w});
    }

    cout << "\nThe spanning tree (source, dest, weight) : "<< spanningTree(V, adj);


    /// (0,0,0) means we are starting from node 0
    /*
    Test case
3 3
0 1 5
1 2 3
0 2 1

    */
    return 0;
}
