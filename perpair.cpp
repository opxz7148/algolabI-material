#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;
int l;
int n;

int weight[MAX_N];
int color[MAX_N];

int pair_num[MAX_N];

void input()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> color[i];
    }
}

int main()
{
    input();

    pair_num[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int this_weight = weight[i];
        int this_color = color[i]; 
        int new_pair_count = 0;

        if (l > this_weight){
            for (int j = i - 1; j >= 0; j--)
            {
                if (this_weight + weight[j] == l && this_color != color[j]){
                    new_pair_count++;
                }
            }
        }

        pair_num[i] = pair_num[i - 1] + new_pair_count;
    }

    cout << pair_num[n - 1] << "\n";
    
}
