#include <iostream>
#include <list>

using namespace std;

int main(){

    int m;
    cin >> m;

    // List for hold the queue
    list<pair<int, int> > q;

    // Array for hold flavour statistics
    int fs[20];

    for(int i = 0; i < 20; i++){
        fs[i] = 0;
    }

    // clear all 

    for(int i = 0; i < m; i++){
        
        // Var for hold event indicator
        int e;
        cin >> e;

        if (e == 1){

            // Get number of new customer in a queue
            int n;
            cin >> n;

            // Get an ID of each customer
            for(int j = 0; j < n; j++){
                int id;
                int flavour;
                cin >> id;
                cin >> flavour;

                q.push_back(pair<int, int>(id, flavour));
            }
        }
        else if (e == 2){

            // Store first customer ID
            pair<int, int> tmp = *q.begin();
            q.pop_front();

            // Print out customer ID that got served
            cout << tmp.first << endl;

            // collect flavour statistics
            fs[tmp.second - 1]++;
        }
    }

    // Print out number of remaining
    cout << q.size() << endl;

    for(int i = 0; i < 20; i++){
        cout << fs[i] << " ";
    }

}