#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int t[n];

    // Input every test case
    for (int i=0; i<n; i++){
        cin >> t[i];
    }

    // calculate result
    for (int i=0; i<n; i++){
        int r = abs(int(((((((t[i] * 567) / 9) + 7492) * 235) / 47) - 498) % 100) / 10);
        cout << r << endl;
    }

}

