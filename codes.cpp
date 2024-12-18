#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
vector<pair<int, int> > diff_freq;
int seq[200000];
int loc[200000];
int n;
int max_seq;
int distinct_count = 0;

void freq_check()
{
    cout << endl;
    for (auto diff: diff_freq)
    {
        cout << diff.first << " " << diff.second << endl;
    }
    cout << endl;

}

bool sortbyf(const pair<int,int> &a, const pair<int,int> &b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void input()
{
    cin >> n;
    int x;
    max_seq = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > max_seq)
        {
            max_seq = x;
        }
        seq[i] = x;
    }
    
}

void init()
{
    for (int i = 0; i < max_seq + 1; i++)
    {
        loc[i] = -1;
    }
}

void diff_update(int diff)
{
    if (loc[diff] == -1)
    {
        loc[diff] = distinct_count;
        diff_freq.push_back(make_pair(diff, 1));
        distinct_count++;
    }
    else
    {
        int x_loc = loc[diff];
        diff_freq[x_loc].second++;
    }
    // freq_check();
}

int main(){
    input();
    init();
    for (int i = 0; i < n - 1; i++){

        int diff = abs(seq[i] - seq[i + 1]);
        // cout << "\n" << diff << "\n";
        diff_update(diff);
        if (i < n - 2)
        {
            int diff2 = abs(seq[i] - seq[i + 2]);
            // cout << "\n" << diff2 << "\n";
            diff_update(diff2);
        }
    }
    sort(diff_freq.begin(), diff_freq.end(), sortbyf);
    // freq_check();
    int ans = (*diff_freq.begin()).first;
    cout << ans << "\n";
}
