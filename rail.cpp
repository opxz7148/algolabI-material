#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_list(list<int> l, string type){

    cout << type << " ";
    for (int a: l){
        cout << a << ", ";
    }
    cout << endl;
}

void print_vector(vector<int> l, string type){

    cout << type << " ";
    for (int a: l){
        cout << a << ", ";
    }
    cout << endl;
}

void check_order(vector<int> order, int n){
    list<int> station;
    list<int> arrive;
    // print_vector(order, "order");

    for (int i = 1; i <= n; i++){
        arrive.push_back(i);
    }

    for (int a: order){
        while (true){
            
            // cout << "a: " << a << endl;
            // cout << endl;
            // print_list(arrive, "arrive");
            // print_list(station, "station");
            // cout << endl;

            // If arrive train at a still remain
            if (!arrive.empty()){

                // Get first coach in arriving.
                int first = *arrive.begin();

                // If number of needed coach more then number of first coach in a arrive.
                if (a > first){
                    // Push first coach into station
                    station.push_front(first);
                    arrive.pop_front();

                // If number of needed coach less then number of first coach in a arrive.
                } else if (a < first){

                    // If station already empty this order is impossible.
                    if (station.empty()){
                        // cout << 1 << endl;
                        cout << "No" << endl;
                        return;

                    // If station still has coach left.
                    } else {

                        // Take the first coach in station.
                        int first_station = *station.begin();

                        // If the number of first coach in station is not equal to
                        // number of needed coach this order is impossible.
                        if (first_station != a){
                            // cout << 2 << endl;
                            cout << "No" << endl;
                            return;

                        // Else move coach out of station
                        } else {
                            station.pop_front();
                            break;
                        }
                    }
                } else {
                    arrive.pop_front();
                    break;
                }
            // If arrive train already out.
            } else {
                // If station already empty this order is impossible.
                if (station.empty()){
                    // cout << 3 << endl;
                    cout << "No" << endl;
                    return;

                // If station still has coach left.
                } else {

                    // Take the first coach in station.
                    int first_station = *station.begin();

                    // If the number of first coach in station is not equal to
                    // number of needed coach this order is impossible.
                    if (first_station != a){
                        // cout << 4 << endl;
                        cout << "No" << endl;
                        return;

                    // Else move coach out of station
                    } else {
                        station.pop_front();
                        break;
                    }
                }
            } 
            // cout << endl;
            // print_list(arrive, "arrive");
            // print_list(station, "station");
            // cout << endl;
        }
    }

    cout << "Yes" << endl;

}

int main(){
    int n;
    while(true){
        cin >> n;

        if (n == 0){
            break;
        } 

        vector<int> order;

        int i = 1;
        while(true){
            int x;
            cin >> x;

            if (x == 0){
                break;
            }

            order.push_back(x);

            if (i == n){
                check_order(order, n);
                order.clear();
                i = 1;
            } else {
                i++;
            }
        }
        cout << endl;

    }
}
