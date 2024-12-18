#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 100010;
vector<int> adj[MAX_N];
vector<int> weight[MAX_N];
int m, s, t, N;
int n = 0;

void read_input()
{
  cin >> n >> m >> s >> t;
  for(int i=0; i<m; i++) {
    int u,v,w;
    cin >> u >> v >> w;

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

void reset()
{
  for (int i = 0; i < n; i++)
  {
    adj[i].clear();
    weight[i].clear();
  }
  
}

void dijkstra(int s)
{
  set<pair<int,int> > Q;

  init();
  dist[s] = 0;

  Q.insert(make_pair(0,s));
  
  while(!Q.empty()) {
  
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
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    reset();
    read_input();
    dijkstra(s);
    if (dist[t] < INF){
      cout << "Case #" << i + 1 << ": " << dist[t] << "\n"; 
    } else {
      cout << "Case #" << i + 1 << ": " << "unreachable" << "\n";
    }
    
  }
  
}