#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

vector<int> has_coffee;
vector<int> has_cookie;

const int MAX_N = 100000;
const int START = 0;
int to_cookie[MAX_N];
int layer[MAX_N];

int n, m, k;
vector<pair<int, int> > adj[MAX_N];
int deg[MAX_N];


void printadj(vector<pair<int, int> > adj[]){
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for (auto a: adj[i]){
            cout << a.first << ":" << a.second << " ";
        }
        cout << endl;
    }
}


void read_input()
{
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x == 1)
    {
      has_coffee.push_back(i);
    } 
    else if (x == 2)
    {
      has_cookie.push_back(i);
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    adj[a].push_back(pair<int, int>(b, w));
    adj[b].push_back(pair<int, int>(a, w));
    deg[a]++;
    deg[b]++; 
  }
  // printadj(adj);
}

void init()
{
  for(int u = 0; u < n; u++) {
    layer[u] = -1;
  }
}

void bfs(int s)
{
  init();
  list<int> Q;

  Q.push_back(s);
  layer[s] = 0;
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int d=0; d<deg[u]; d++) {

      // cout << "from " << u << "\n"; 
      int v = adj[u][d].first;
      int w = adj[u][d].second;
      
      if ((layer[v] != -1 && layer[u] + w <= layer[v]) || layer[v] == -1) {
        Q.push_back(v);
        layer[v] = layer[u] + w;

      }

    }
  }
}

void find_cookies()
{
  if (k == 2)
  {
    for (int coffee_index: has_coffee)
    {
      bfs(coffee_index);
      int close_c = INT_MAX;
      for (int cookie_index: has_cookie)
      {
        if (layer[cookie_index] < close_c)
        {
          close_c = cookie_index;
        }
      }
      to_cookie[coffee_index] = close_c;
    }
  }
}

int main()
{
  read_input();
  init();
  find_cookies();
  bfs(0);

  int ans = INT_MAX;

  // for (int i = 0; i < n; i++)
  // {
  //   cout << layer[i] << "\n";
  // }
  

  // if (k == 1)
  // {
  //   for (int coffee_index: has_coffee)
  //   {
  //     // cout << coffee_index << " ";
  //     if ((layer[coffee_index] < ans) && layer[coffee_index] != -1)
  //     {
  //       ans = layer[coffee_index];
  //     }
  //   }
  //   // cout << endl;
  // } else 
  // {
  //   for (int coffee_index: has_coffee)
  //   {
  //     if (layer[coffee_index] + to_cookie[coffee_index] < ans && layer[coffee_index] != -1)
  //     {
  //       ans = layer[coffee_index] + to_cookie[coffee_index];
  //     }
  //   }
  // }
  cout << ans << '\n';

}