#include <iostream>
#include <queue>

#define NODE_MAX 10
#define INF -1

using namespace std;

int adj_matrix[NODE_MAX][NODE_MAX];

int min_distance[NODE_MAX];
int predecessor[NODE_MAX];
bool visited[NODE_MAX];

typedef struct NodePair {
  int nodeIndex;
  int distance;
} NodePair;

struct Compare {
  bool operator()(const NodePair& lhs, const NodePair& rhs) const {
    return lhs.distance > rhs.distance;
  }
};

void load_matrix() {
  int n;
  int node1, node2, weight;

  // init
  for (int x = 0; x < NODE_MAX; x++)
    for (int y = 0; y < NODE_MAX; y++) adj_matrix[x][y] = INF;

  // number of edga
  cin >> n;

  // load edga
  while (n > 0) {
    cin >> node1 >> node2 >> weight;
    adj_matrix[node1][node2] = weight;
    adj_matrix[node2][node1] = weight;
    n--;
  }
}

void dijkstra(int start) {
  priority_queue<NodePair, vector<NodePair>, Compare> pq;

  // init
  for (int i = 0; i < NODE_MAX; i++) {
    min_distance[i] = INF;
    predecessor[i] = -1;
    visited[i] = false;
  }

  min_distance[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    // extract min
    int u = pq.top().nodeIndex;
    pq.pop();

    // mark visited
    visited[u] = true;

    // for each u.adj
    for (int v = 0; v < NODE_MAX; v++) {
      if (adj_matrix[u][v] == INF) continue;

      // relax
      if (min_distance[v] == INF ||
          min_distance[v] > min_distance[u] + adj_matrix[u][v]) {
        predecessor[v] = u;
        min_distance[v] = min_distance[u] + adj_matrix[u][v];
      }

      if (!visited[v]) pq.push({v, min_distance[v]});
    }
  }
}

void printTable() {
  cout << "distance" << endl;
  for (int i = 0; i < NODE_MAX; i++) cout << "\t" << i;
  cout << endl;

  for (int i = 0; i < NODE_MAX; i++) cout << "\t" << min_distance[i];
  cout << endl;

  cout << "predecessor" << endl;
  for (int i = 0; i < NODE_MAX; i++) cout << "\t" << i;
  cout << endl;

  for (int i = 0; i < NODE_MAX; i++) cout << "\t" << predecessor[i];
  cout << endl;
}

int main() {
  int start;
  load_matrix();
  cin >> start;
  dijkstra(start);
  printTable();

  return 0;
}
