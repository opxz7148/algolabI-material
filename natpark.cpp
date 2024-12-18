#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_M = 200010;
const int MAX_N = 100010;

int n,m;
int edges[MAX_M][2];
int weights[MAX_M];
vector<pair<int,int> > sorted_edges;
vector<int> forest;

void read_input()
{
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int a,b,w;
    cin >> a >> b >> w;
    a--; b--;
    edges[i][0] = a;
    edges[i][1] = b;
    weights[i] = w;

    if (w == -1){
      forest.push_back(i);
    } else {
      sorted_edges.push_back(make_pair(w,i));
    }
  }
}

int parents[MAX_N];
int ranks[MAX_N];

void init_union_find()
{
  for(int i=0; i<n; i++) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int find(int u)
{
  if(parents[u] == u)
    return u;
  else {
    int p = find(parents[u]);
    parents[u] = p;
    return p;
  }
}

void union_sets(int pu, int pv)
{
  if(parents[pu] != pu)
    pu = find(pu);
  if(parents[pv] != pv)
    pv = find(pv);
  if(pu == pv)
    return;

  if(ranks[pv] > ranks[pu]) {
    parents[pu] = pv;
  } else {
    if(ranks[pv] == ranks[pu])
      ranks[pu]++;
    
    parents[pv] = pu;
  }
}

pair<int, int> mst()
{
  int mst_weights = 0;
  int forest_count = 0;
  init_union_find();
  
  sort(sorted_edges.begin(), sorted_edges.end());

  for (pair<int, int> i: sorted_edges) {
    int e = i.second;
    int u = edges[e][0];
    int v = edges[e][1];
    int w = weights[e];

    // check if u and v belongs to the different components
    int pu = find(u);
    int pv = find(v);

    // TODO: your code here
    if(pu != pv) {   // TODO: your condition here
      // add e to the tree
      mst_weights += w;
	
      // update the data structure
      // TODO: your code here
      union_sets(pu, pv);
    }
  }

  for (int e: forest){
    int u = edges[e][0];
    int v = edges[e][1];

    // check if u and v belongs to the different components
    int pu = find(u);
    int pv = find(v);

    if(pu != pv) { 
      // update the data structure
      union_sets(pu, pv);
      forest_count++;
    }
  }
  return pair<int, int>(forest_count, mst_weights);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  read_input();
  auto result = mst();
  cout << result.first << " " << result.second << "\n";
  return 0;
}