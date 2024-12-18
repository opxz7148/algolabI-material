#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<long> bag_total;

void input(){
    cin >> n >> k;
    long s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        bag_total.push_back(s * 10);
    }
}

int main(){

    input();

    long must_hold = 0;
    int big_count = 0;

    for (int i = 0; i < k; i++)
    {
        must_hold = must_hold + bag_total[i];
    }

    for (int i = k; i < n; i++)
    {
        if (bag_total[i] >= must_hold){
            big_count += 1;
        }
    }
        
    cout << big_count << "\n";
}
