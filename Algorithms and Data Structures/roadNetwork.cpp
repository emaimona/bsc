#include <bits/stdc++.h>

using namespace std;
vector<int> dis;
vector<int> par;
int A;
int B;


/*
Given a map of a road network. We know the maximum width of trucks that can drive on each road section. Let's give an algorithm that determines the maximum width of a truck that can be used to get from A to B. (You can choose the graph representation.)

*/


/*
    Test case

Vertices followed by Edges:
6 10
0 1 5
0 4 2
0 3 4
1 2 1
1 4 2
1 3 1
4 3 2
4 5 1
5 2 3
2 4 1

Give A followed by B
0 1

Ouput = 5
*/


// [IMPORTANT]

/* I am considering the edges as the widht of the roads, therefore the minumum widht of a road in the path A to B, will determine the max Width of the Truec

The graph is directed
*/

void fillParents() {
    for (int i=0; i<par.size(); i++)
        par[i] = i;
}

int getMin(int n, int minw) {
    if (par[n] == n)
        return minw;

    minw = abs(minw-dis[par[n]]);
    return getMin(par[n], minw);
}

void printShortestPaths() {
    cout<< endl<<"The shortest paths from " << A << ": "<<endl;
    for(int i=0; i<dis.size(); i++)
        cout<< i << " := "<<dis[i] << endl;
}

void printParents() {
    cout<< endl<<"The Parents  " <<endl;
    for(int i=0; i<par.size(); i++)
        cout<< i << " := "<< par[i] << endl;
}

typedef pair<int, int> pr;
void dijkstra(vector<vector<int>> adj[]){
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    pq.push({0, A});
    while (!pq.empty()) {
        auto node = pq.top();
        int w = node.first;
        int s = node.second;
        pq.pop();
        
        for (auto i: adj[s]) {
            int dest = i[1];
            int dweight = i[0]; 
            
            if (dis[s]+dweight < dis[dest]) {
                par[dest] = s;
                dis[dest] = dis[s]+dweight;
                pq.push({dweight, dest});
            }
        }
    }
}
int main() {

    // V -> number of Vertices
    // E -> number of Edges
    
    int V, E;
    cout<< "Vertices followed by Edges: \n";
    cin>> V >> E;

    // Resizing the vectors with initial values
    dis.resize(V, 1e9);
    par.resize(V);
    fillParents();
    
    int i = 0;
    vector<vector<int>> adj[V];
    while (i++<E) {
        int s, d, w;
        cin>> s>> d>> w;
        // Direct graph
        adj[s].push_back({w, d});
    }

    // A -> Source, B-> Destination
    cout << "Give A followed by B"<< endl;
    cin >> A >> B;
    dis[A] = 0;
    
    dijkstra(adj);
    printShortestPaths();
    printParents();
    
    int minWeight = getMin(B, dis[B]);
    cout<<endl<< "The minumum truck size is "<< minWeight<<endl;

    
    return 0;
}

