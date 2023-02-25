// The following code represents the implementation of a DFS algorithm
// to find the shortest path between two nodes in a graph.
// The graph is represented as an adjacency list.
// The algorithm is implemented using a stack.

#include <bits/stdc++.h>

using namespace std;


vector<int> DFS(vector<vector<int>> &adj, int s, int t) {
  stack<vector<int>> path_stack;
  vector<int> path;
  vector<int> visited(adj.size(), 0);
  path_stack.push({s});
  while (!path_stack.empty()) {
    path = path_stack.top();
    path_stack.pop();
    int last = path[path.size() - 1];
    if (last == t) {
      return path;
    }
    if (visited[last] == 0) {
      visited[last] = 1;
      for (int i = 0; i < adj[last].size(); i++) {
        if (visited[adj[last][i]] == 0) {
          vector<int> new_path(path);
          new_path.push_back(adj[last][i]);
          path_stack.push(new_path);
        }
      }
    }
  }
  return {};
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;
  x--, y--;
  vector<int> path = DFS(adj, x, y);
  for (int i = 0; i < path.size(); i++) {
    cout << path[i] + 1 << " ";
  }
}