#include <iostream>

using namespace std;

void sort(int a[], int n){

    // cout << "n: " << n << endl;

    // cout << "Array before : ";
    // for (int i = 0; i < n + 1; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = n; i >= 0; i--){


        if (a[i] < a[i-1]) {
            int tmp = a[i - 1];
            a[i - 1] = a[i];
            a[i] = tmp;
        } else {
            break;
        }
    }

    // cout << "Array after : ";
    // for (int i = 0; i < n + 1; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}

int main(){

    int a[10000];

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    int x;
    while (cin >> x)
    {
        a[n] = x;
        // cout << "n: " << n << endl;
        sort(a, n);

        int index = int(n / 2);
        int med;

        // cout << "median ";

        if (n % 2 == 0){
            cout << a[index] << endl;
        } else {
            cout << int((a[index] + a[index + 1]) / 2) << endl;
        }

        n++;

    }
}
