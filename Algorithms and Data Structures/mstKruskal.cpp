#include <bits/stdc++.h>
using namespace std;


vector<int> par;
vector<int> ranks;

class Edge {
public:
  int s;
  int d;
  int w;
};

int find(int val) {
    if (par[val] == val)
        return val;
    return par[val] = find(par[val]);
}

void unite(int val1, int val2) {
    int p1 = find(val1);
    int p2 = find(val2);
    
    if (ranks[p1] < ranks[p2]) {
        par[p1] = p2;
        ranks[p2] += ranks[p1];
    } else {
        par[p2] = p1;
        ranks[p1] += ranks[p2];
    }
}

static bool compare(Edge v1, Edge v2) {
    return (v1.w < v2.w);
}

string spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<Edge> lis;
    string mst = "";
    
    par.resize(V);
    ranks.resize(V, 1);

    // Rearanging edges => MIn Priority queue could also be used
    for (int i=0; i<V; i++) {
        par[i] = i;
        for (auto n: adj[i]) {
            Edge e;
            e.s = i;
            e.d = n[0];
            e.w = n[1];
            lis.push_back(e);
        }
    }
    
    sort(lis.begin(), lis.end(), compare);
    
    int wsum = 0;

    for (auto e: lis) {
        int s = e.s;
        int d = e.d;
        int w = e.w;
            
        int ps = find(s);
        int pd = find(d);
        if (pd != ps) {
            wsum += w;
            mst += "("+to_string(s)+", "+to_string(d)+", "+to_string(w)+") -> ";
            unite(ps, pd);
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

    cout << "\nThe spanning tree (source, dest, weight) : "<< spanningTree(V, adj)<<endl;


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
