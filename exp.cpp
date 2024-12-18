#include <iostream>
using namespace std;

int main(){

    int sum = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){

        int exp = 0;

        cin >> exp;

        if (i % 4 == 0){
            exp = exp * 2;
        }

        sum = sum + exp;
    }

    cout << sum << endl;

}

