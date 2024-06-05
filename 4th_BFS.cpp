#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); 
        vector<int> bfs; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector <int> adj[V];
    
    cout << "Enter the edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}

/*
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (u v):
0 1
1 2
1 3
0 4
output:-
0 1 4 2 3 
*/