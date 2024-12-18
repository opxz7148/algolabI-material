#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int MAX_N = 30;

int top, good = 0;
int con_count = 0;
int min_count, for_count = 0;

int m,n;
vector< pair<int, int> > adj[MAX_N][MAX_N];
int deg[MAX_N][MAX_N];

char map[MAX_N][MAX_N];

void print_adj(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << "adj: " << i << " " << j << ": ";
            for (auto a: adj[i][j]) {
                cout << "{" << a.first << ", " << a.second << "}";
            }
            cout << "\n";
        }
    }
}

void print_map(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void read_input()
{
  string row;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> row;
    for(int j = 0; j < m; j++){
        map[i][j] = row.at(j);
    }
  }
}

bool seen[MAX_N][MAX_N];
int layer[MAX_N][MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    for(int x = 0; x < m; x++){
      seen[u][x] = false;
      layer[u][x] = -1;
    }
  }
}

void reset_reg(){
    for_count = 0;
    min_count = 0;
    con_count = 0;
}

void bfs(pair<int, int> s)
{
  list<pair <int, int> > Q;

  Q.push_back(s);
  seen[s.first][s.second] = true;
  layer[s.first][s.second] = 0;
  
  while(!Q.empty()) {
    auto u = Q.front();

    char curr_node = map[u.first][u.second];

    con_count++;

    if (curr_node == '*'){
    for_count++;
    } else if (curr_node == '$'){
    min_count++;
    }

    Q.pop_front();
    for(int d=0; d<deg[u.first][u.second]; d++) {
      pair<int, int> v = adj[u.first][u.second][d];
      if(!seen[v.first][v.second]) {
        Q.push_back(v);
        seen[v.first][v.second] = true;
        layer[v.first][v.second] = layer[u.first][u.second] + 1;
      }
    }
  }
}

void connect_graph(){
// Connect all node
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        if (map[i][j] != '#'){
            if (i != n - 1){
                if (map[i + 1][j] != '#'){
                    adj[i][j].push_back(pair<int, int>(i + 1, j));
                    deg[i][j]++;

                    adj[i + 1][j].push_back(pair<int, int>(i, j));
                    deg[i + 1][j]++;
                }
            }

            if (j != m - 1){
                if (map[i][j + 1] != '#'){
                    adj[i][j].push_back(pair<int, int>(i, j + 1));
                    deg[i][j]++;
                    
                    adj[i][j + 1].push_back(pair<int, int>(i, j));
                    deg[i][j + 1]++;
                }
            }
        }
    }
  }
}

int main()
{
  read_input();
  init();
  cout << "\n";
  //print_map();
  connect_graph();
  //print_adj();

  init();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if (layer[i][j] == -1 && map[i][j] != '#'){
            reset_reg();
            bfs(pair<int, int>(i, j));

            if (min_count >= 1 && for_count >= 1){
                top = top + con_count;
            } else if (min_count >= 1 || for_count >= 1){
                good = good + con_count;
            }
        } 
    }
  }

  cout << top << " " << good << "\n";
}