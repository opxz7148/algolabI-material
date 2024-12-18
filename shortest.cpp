#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 100010;
vector<int> adj[MAX_N];
vector<int> weight[MAX_N];
int n,m;

void read_input()
{
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;

    adj[u].push_back(v);
    weight[u].push_back(w);

    adj[v].push_back(u);
    weight[v].push_back(w);
  }
}

const int INF = 1000000001;
int dist[MAX_N];
bool scanned[MAX_N];
int parent[MAX_N];

void init()
{
  for(int u=0; u<n; u++) {
    dist[u] = INF;
    scanned[u] = false;
    parent[u] = -1;
  }
}

void dijkstra(int s)
{
  set<pair<int,int> > Q;

  init();
  dist[s] = 0;

  // Initialize queue
  // We insert (0,s), i.e., the distance is 0 and the vertex index is s 
  Q.insert(make_pair(0,s));
  
  while(!Q.empty()) {
    // TODO: Extract from the queue here and
    //   let u be the vertex.
    //   Recall that Q.begin() is an iterator pointing to the first element.
    //   You can dereference it to get to the pair.
    //   First element in the pair is the distance (for sorting),
    //   and the second element is the vertex index.
    //   Don't forget to remove Q.begin() from the queue (Q), using erase

    auto du = *(Q.begin());
    Q.erase(Q.begin());

    int u = du.second;   //  fix this line too!

    if(scanned[u])
      continue;

    scanned[u] = true;

    int deg = adj[u].size();
    for(int d=0; d<deg; d++) {
      int v = adj[u][d];
      int w = weight[u][d];

      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        parent[v] = u;

        // TODO: add (dist[v],v) to the queue
        Q.insert(make_pair(dist[v], v));
      }
    }
  }
}

int main()
{
  read_input();
  dijkstra(0);
  cout << dist[n-1] << endl;
}