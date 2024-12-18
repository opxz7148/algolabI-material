#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int MAX_N = 1010;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool seen[MAX_N];
int layer[MAX_N];
int n, m, t, s;

// void printadj(vector<int> adj[]){
//     cout << "\n";
//     for(int i = 0; i <= n + 1; i++){
//         cout << i << ": ";
//         for (int a: adj[i]){
//             cout << a << " ";
//         }
//         cout << endl;
//     }
//     cout << "\n";
// }

void bfs(int s)
{
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int d=0; d<deg[u]; d++) {

      int v = adj[u][d];

      if(!seen[v]) {
        Q.push_back(v);
        seen[v] = true;
        layer[v] = layer[u] + 1;
      }
    }
  }
}

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

void input(){
    
    cin >> n >> m >> t >> s;
    for (int i = 0; i < m; i++)
    {
        int l;
        cin >> l;
        int stop[l];
        for (int j = 0; j < l; j++){
            int x;
            cin >> x;
            stop[j] = x;

            for (int k = 0; k < j; k++){
                // cout << "I\n";
                adj[x].push_back(stop[k]);
                deg[x]++;
                adj[stop[k]].push_back(x);
                deg[stop[k]]++;
            }
            
            // printadj(adj);

        }
    }
    
}

int main(){
    input();
    init();
    // printadj(adj);
    bfs(s);
    cout << layer[t] << "\n";
}
