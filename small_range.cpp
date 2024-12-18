#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> items;
int n, l;

void input()
{
    cin >> n >> l;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        items.push_back(x);
    }
    sort(items.begin(), items.end());
}

int main(){

    input();
    // for (int item: items)
    //     {
    //         cout << item << " ";
    //     }
    // cout << endl;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            // cout << "i: " << items[i] << " " << "j: " << items[j] << "\n";
            if ((items[j] - items[i]) <= l)
            {
                // cout << j - l << "\n";
                if (j - i + 1 > ans)
                {
                    ans = j - i + 1;
                }
                break;
            }
        }
    }
    cout << ans << "\n";
    
}
