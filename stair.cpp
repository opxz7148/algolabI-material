#include <iostream>

using namespace std;

const int MOD = 9377;
const int MAX_N = 1010;

int stairs[MAX_N];
int n, k;

int main(){
    cin >> n >> k;
    stairs[0] = 1;
    stairs[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int stair_ways = 0;
        for (int j = 1; j <= k + 1; j++)
        {
            if (i - j < 0)
            {
                break;
            }
            stair_ways += stairs[i - j];
        }
        stairs[i] = stair_ways % MOD;
    }

    cout << stairs[n] << "\n";
}
