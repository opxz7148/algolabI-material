#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int COIN_SET[4] = {5, 10, 25, 50};

int match_num(int num){
    int ans = 0;
    for (int j = 0; j < 4; j++)
    {
        if (num % COIN_SET[j] == 0){
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main(){
    int com_count = 1;
    int coin;
    cin >> coin;

    for (int i = 2; i <= coin; i++)
    {
        int add = match_num(i);
        com_count += add;

        cout << "i: " << i << " " << com_count << "\n";
    }

    cout << com_count << "\n";
    

}
