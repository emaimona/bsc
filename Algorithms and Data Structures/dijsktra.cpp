#include <bits/stdc++.h>

using namespace std;
vector<int> dis;
int S;
void print() {
    cout<< endl<<"The shortest paths from " << S<< ": "<<endl;
    for(int i=0; i<dis.size(); i++)
        cout<< i << " := "<<dis[i] << endl;
}

typedef pair<int, int> pr;
void dijkstra(vector<vector<int>> adj[]){
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    pq.push({0, S});

    while (!pq.empty()) {
        auto node = pq.top();
        int w = node.first;
        int s = node.second;
        pq.pop();
        
        for (auto i: adj[s]) {
            int dest = i[1];
            int dweight = i[0]; 
            
            if (dis[s]+dweight < dis[dest]) {
                dis[dest] = dis[s]+dweight;
                pq.push({dweight, dest});
            }
        }
    }
}
int main() {
    int V, E;
    cout<< "Vertices followed by Edges: \n";
    cin>> V >> E;

    S=0; // source vector
    // 1e9 => infinite;
    dis.resize(V, 1e9);
    dis[S] = 0;
    
    int i = 0;
    vector<vector<int>> adj[V];
    
    while (i++<E) {
        int s, d, w;
        cin>> s>> d>> w;
        // undirect graph
        adj[s].push_back({w, d});
        adj[d].push_back({w, s});
        
    }
    //cin>> S;
/*
    Test case
3 3
0 1 5
1 2 3
0 2 1
*/
    dijkstra(adj);
    print();
    return 0;
}