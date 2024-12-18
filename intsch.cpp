#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > req;
int n;

bool sortByEnd(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return a.second < b.second;
}

void input(){
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        req.push_back(pair<int, int>(s, t));
    }
}

void printvec(){
    for(auto a: req){
        cout << a.first << " " << a.second << "\n";
    }
}

int main(){
    cin >> n;
    input();
    sort(req.begin(), req.end(), sortByEnd);
    // printvec();

    int ans = 0;

    int cur_end = -1; 

    for (auto a: req){
        if (a.first >= cur_end){
            cur_end = a.second;
            ans++;
        }
    }

    cout << ans << endl;
}
