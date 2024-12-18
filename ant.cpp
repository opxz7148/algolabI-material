#include <iostream>
using namespace std;

int main(){

    int sum = 0;
    int n;
    cin >> n;

    int ant[n];

    for(int i = 0; i < n; i++){

        cin >> ant[i];

    }

    for(int i = 0; i < n; i++){

        if(ant[i] >= 1000){
            if(i != n-1){
                ant[i + 1] = 0;
            }
            ant[i + 1] = 0;
            sum += 1000;
            continue;
        }

        sum = ant[i] + sum;
    }

    


    cout << sum << endl;

}

