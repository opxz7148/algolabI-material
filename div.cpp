#include <iostream>
#include <list>
using namespace std;

int main(){

    // Iterate forever
    while (true) {

        // Get number of query in test case
        int n;
        cin >> n;
        
        // Exit if number of query = 0
        if (n <= 0){
            break;
        }

        // Get division point
        int div_x, div_y;
        cin >> div_x >> div_y;

        for (int i = 0; i < n; i ++){
            int x;
            int y;
            cin >> x >> y;

            if (x == div_x || y == div_y){
                cout << "divisa" << endl;
            } else {
                if (x > div_x && y > div_y){
                    cout << "NE" << endl;
                } else if (x < div_x && y > div_y){
                    cout << "NO" << endl;
                } else if (x < div_x && y < div_y){
                    cout << "SO" << endl;
                } else if (x > div_x && y < div_y){
                    cout << "SE" << endl;
                }
                
            }
        }

        
    }
}

