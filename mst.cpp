#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_M = 200010;
const int MAX_N = 100010;

int n,q;
int edges[MAX_M][2];
int weights[MAX_M];
vector<pair<int,int> > sorted_edges;

void read_input()
{
  cin >> n >> q;
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

void query(int pu, int pv)
{
  if (pu == pv)
  {
    cout << "yes" << "\n";
  } 
  else
  {
    cout << "no" << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  read_input();
  init_union_find();
  int x, y;
  char a;
  for (int i = 0; i < q; i++)
  {
    cin >> a >> x >> y;

    x--; y--;

    int px = find(x);
    int py = find(y);

    if (a == 'q'){
      query(px, py);
    } else {
      union_sets(px, py);
    }
  }
  
}

