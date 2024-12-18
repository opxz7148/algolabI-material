#include <iostream>
#include <vector>

using namespace std;

int stop[1010];
int n;

void input(){
    cin >> n;
    stop[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        stop[i] = h;
    }
    
}

int main(){
    int m = 0;
    int energy = 0;
    input();
    for (int i = 1; i < n + 1; i++)
    {
        if (stop[i] > stop[i - 1])
        {
            energy += (stop[i] - stop[i - 1]) + m;
            m += 1;
        } else {
            m = 0;
        }
    }
    cout << energy << "\n";
}
