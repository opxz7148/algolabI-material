#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int banana[100010];
pair<int, bool> result[100010];
int n;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> banana[i];
    }
    
}

int main(){

    input();

    result[0] = make_pair(0, false);
    result[1] = make_pair(0, false);

    for (int i = 2; i < n; i++)
    {
        pair<int, bool> dont_get_this_banana = make_pair(result[i-1].first, false);
        pair<int, bool> get_this_banana;

        if (result[i - 2].second)
        {
            get_this_banana.first = result[i - 3].first + banana[i];
        } else 
        { 
            get_this_banana.first = result[i - 2].first + banana[i];
        }
        get_this_banana.second = true;
        result[i] = max(get_this_banana, dont_get_this_banana);
        // cout << result[i].first << "\n";
    }
    
    cout << result[n - 1].first << "\n";
}
