#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int coupon[1000];
int ccount[1000];
int n, w;

void input(){
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {   
        cin >> coupon[i];
    }
}

int main(){
    input();
    for (int i = n - 1; i >= 0; i--)
    {
        ccount[i] = w / coupon[i];
        w %= coupon[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ccount[i] << " ";
    }
    
    cout << "\n";
}
