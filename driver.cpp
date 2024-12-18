#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> morning;
vector<int> evening;

int n, d, r;

void input(){
    morning.clear();
    evening.clear();
    for (int i = 0; i < n; i++)
    {
        int morning_route;
        cin >> morning_route;
        morning.push_back(morning_route);
    }
    for (int i = 0; i < n; i++)
    {
        int evening_route;
        cin >> evening_route;
        evening.push_back(evening_route);
    }
    sort(morning.begin(), morning.end());
    sort(evening.begin(), evening.end(), greater<int>());
}

void print_morning(){
    for (auto a: morning){
        cout << a << " ";
        cout << endl;
    }
}

int main(){
    while (true)
    {
        cin >> n >> d >> r;
        int total_pay = 0;
        if (n == 0 && d == 0 && r == 0){
            break;
        }
        input();
        for (int i = 0; i < n; i++)
        {
            int morning_r = morning[i];
            int evening_r = evening[i];

            int total_hour = morning_r + evening_r;
            if ((total_hour) > d ){
                total_pay += (total_hour - d) * r;
            }
        }
        cout << total_pay << '\n';
    }
}
