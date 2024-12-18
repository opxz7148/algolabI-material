#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<pair<int, int> > houses;

void input(){
    cin >> n >> l;
    int s, t;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        houses.push_back(pair<int, int>(s, t));
    }
}

int main(){
    int fence_ended = 0;
    int fence_count = 0;

    input();

    for (auto house: houses) {

        int s = house.first;
        int t = house.second;

        if (fence_ended < t) {
            fence_ended = s + l;
            fence_count++;
        }
    }
    cout << fence_count << "\n";
}