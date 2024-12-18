#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

vector<int> ball_worth;

void input(){
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ball_worth.push_back(x - y);
    }
    
}

bool comp(int a, int b){
    return a > b;
}

int main(){

    input();

    sort(ball_worth.begin(), ball_worth.end());

    int sum = 0;

    // for (int a: ball_worth){
    //     cout << a << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (ball_worth[i] < 0 && k > 0){
            k--;
            continue;
        } else {
            sum = sum + ball_worth[i];
        }
    }
    cout << sum << "\n";
    
}
