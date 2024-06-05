#include <bits/stdc++.h>
using namespace std;

void BestFS(vector<vector<pair<int, int>>>& graph, int start) 
{
    	int V = graph.size(); 
    	vector<bool> visited(V, false); 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    	pq.push({0, start}); // {heuristic, vertex}

    	while (!pq.empty())
 {
        // Pop the vertex with the highest priority (lowest heuristic value)
        		int current = pq.top().second;
       		pq.pop();

        // If the vertex has not been visited, mark it as visited and print it
        		if (!visited[current])
{
            			cout << current << " ";
            			visited[current] = true;
        		}

        // If an adjacent has not been visited, push it onto the priority queue with its heuristic value
        		for (auto& neighbor : graph[current]) 
{
            			int vertex = neighbor.first;
            			int heuristic = neighbor.second; 
            			if (!visited[vertex]) 
{
               			 pq.push({heuristic, vertex});
            			}
        		}
    	}
}

int main() {
    	int V, E; 
    	cout << "Enter the number of vertices: ";
    	cin >> V;
    	cout << "Enter the number of edges: ";
    	cin >> E;  

    	vector<vector<pair<int, int>>> graph(V);
    	cout << "Enter the edges (format: start_vertex end_vertex heuristic):\n";
    	for (int i = 0; i < E; ++i) 
{
        		int start, end, heuristic;
        		cin >> start >> end >> heuristic;
        		graph[start].push_back({end, heuristic});
    	}

    	int startNode;
    	cout << "Enter the starting node for Best First Search traversal: ";
    	cin >> startNode;

   	 cout << "Best First Search traversal (starting from node " << startNode << "): ";
    	BestFS(graph, startNode);

    	return 0;
}

/*
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (format: start_vertex end_vertex heuristic):
0 1 2
0 2 4
1 2 1
1 3 5
2 3 3
3 4 1
Enter the starting node for Best First Search traversal: 0

output:-
Best First Search traversal (starting from node 0): 0 1 2 3 4 
*/