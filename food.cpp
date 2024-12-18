#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100010;

bool sortbyf(const pair<int,int> &a, const pair<int,int> &b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){

    int n;
    int distinct_count = 0;

    bool checker[MAX];
    int loc[MAX];
    vector<pair<int, int> > val_count;
    
    for (int i = 0; i < MAX; i++){
        checker[i] = false;
        loc[i] = -1;
    }

    cin >> n;

    int x;

    for (int i = 0; i < n; i++){

        cin >> x;

        if (!checker[x]){
            // cout << "done 1\n";
            loc[x] = distinct_count;
            // cout << "done 2\n";
            checker[x] = true;
            // cout << "done 3\n";
            val_count.push_back(pair<int, int>(x, 1));
            // cout << "done 4\n";
            distinct_count++;
        } else {
            int x_loc = loc[x];
            val_count[x_loc].second++;
        }

    }

    sort(val_count.begin(), val_count.end(), sortbyf);

    int fav_count = (*val_count.begin()).second;
    for (auto a: val_count){
        if (a.second < fav_count)
        {
            break;
        }
        cout << a.first << " ";
    }
    cout << "\n";
}
