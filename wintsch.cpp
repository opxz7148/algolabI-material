#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct request {
    int s;
    int t;
    int w;
    int i;
};

int MAX_N = 10000;
int n;
vector<request> requests;

pair<int, vector<int>> ans[10000];

bool comp(const request &a, const request &b){
    return a.t < b.t;
}
void input(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        request r;
        cin >> r.s >> r.t >> r.w;
        r.i = i + 1;
        requests.push_back(r);
    }
    sort(requests.begin(), requests.end(), comp);
}

int main(){
    input();

    // ans[0] = pair<int, vector<int> >()

    for (request r : requests){

    }
}
