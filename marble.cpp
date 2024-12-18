#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int find_in_sort_arr(int arr[], int l, int r, int x){

    int n = r - l;

    int m = ceil(n / 2.0);

    // cout << "l: " << l << " r: " << r << " n: " << n << " m: " << m << " x: " << x << " arr[l + m] " << arr[l+m] << endl;

    if (n == 0){
        // cout << "I'm in here" << endl;
        if (arr[l] == x){
            return 0;
        }
        return -1;
    }
     
    int result;

    if (x > arr[l + m]){

        result = find_in_sort_arr(arr,l + m, r, x);
        if (result == -1){
            return -1;
        }

        return m + result;


    } else if (x < arr[l + m]){

        result = find_in_sort_arr(arr, l, m + l - 1, x);
        if (result == -1){
            return -1;
        }

        return result;

    } else {
        result = find_in_sort_arr(arr, l, m + l - 1, x);

        if (result < m && result != -1){
            return result;
        }
        return m;
    }

}


int main(){

    int c = 0;
    
    while (true){

        c++;

        int n, q;
        cin >> n >> q;

        if (n == 0 && q == 0){
            break;
        }

        int marble[n];

        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            marble[i] = x;
        }

        // cout << "Finish create arr" << endl;

        int size = sizeof(marble) / sizeof(marble[0]);
        sort(marble, marble + size);

        cout << "CASE# " << c << ":" <<endl;

        for (int i = 0; i < q; i++){

            int x;
            cin >> x;

            int ans = find_in_sort_arr(marble, 0, n - 1, x);

            if (ans != -1){
                cout << x << " found at " << ans + 1 << endl;
            } else {
                cout << x << " not found" << endl;
            }
        }
    }
}
