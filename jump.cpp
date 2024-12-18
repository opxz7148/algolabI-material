#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

const int MAX_N = 1000010;
const int START = 0;
int DEST;


int n, r;
vector<int> adj[MAX_N];
int deg[MAX_N];
pair<int, int> coord[MAX_N];

void printadj(vector<int> adj[]){
    for(int i = 0; i <= n + 1; i++){
        cout << i << ": ";
        for (int a: adj[i]){
            cout << a << " ";
        }
        cout << endl;
    }
}

float distance(pair<int, int> c1, pair<int, int> c2){


    // Get different of each axis coord
    int dx = abs(c1.first - c2.first);
    int dy = abs(c1.second - c2.second);

    // Calculate distance
    float dis = sqrt((pow(dx, 2)) + (pow(dy, 2)));
    
    // cout << "(" << c1.first << ", " << c1.second << ")" << endl;
    // cout << "(" << c2.first << ", " << c2.second << ")" << endl;
    // cout << "Distance: " << dis << endl;

    return dis;
}


void read_input()
{
  cin >> n >> r;

  DEST = n + 1;

  // Set up start and destination tree coordinate
  coord[START] = pair<int,int>(0, 0);
  coord[DEST] = pair<int, int>(100, 100);

  for(int i = 0; i <= n + 1; i++)
    deg[i] = 0;

  if (distance(coord[START], coord[DEST]) <= r){
    adj[START].push_back(DEST);
    adj[DEST].push_back(START);
    deg[START] += 1;
    deg[DEST] += 1;
  }
  
  // Get every tree coordinates
  for(int i = 1; i < n + 1; i++) {
    int x,y;
    cin >> x >> y;
    
    // Record coordinate
    coord[i] = pair<int, int>(x, y);

    // calculate distance with every previous tree
    // If distance between 2 tree less then or equal to r add both to each other adj list
    for(int j = 0; j < i; j++){
        if (distance(coord[i], coord[j]) <= r){
            adj[i].push_back(j);
            adj[j].push_back(i);
            deg[i] += 1;
            deg[j] += 1;
        }
    }

    // Compare with destination tree
    if (distance(coord[i], coord[DEST]) <= r){
        adj[i].push_back(DEST);
        adj[DEST].push_back(i);
        deg[i] += 1;
        deg[DEST] += 1;
    }
  }
}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

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

int main()
{
  read_input();
  init();
  bfs(0);
  // printadj(adj);
  // for(int u=0; u<=n+1; u++) {
  //   cout << u << " " << layer[u] << endl;
  // }

  int ans = layer[n + 1];

  if (ans == 0){
    cout << -1;
  } else {
    cout << layer[n + 1] << endl;
  }

}