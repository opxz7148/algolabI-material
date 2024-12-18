#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> l){

    cout << endl;
    cout << "List:";
    for (int a: l){
        cout << a << " ";
    }
    cout << endl;

}

int main(){

    // Get number of operation
    int t;
    cin >> t;

    // Row of cookies
    list<int> r;

    for (int i = 0; i < t; i++){
        // print_list(r);

        // cout << "i:" << i << endl;

        // Action indicator
        int l;
        cin >> l;
         
        // Choose to add new cookie
        if (l == 1){
            int k, x;
            cin >> k >> x;

            // If insert pos more then row size add end of row
            if (k > r.size()){
                r.push_back(x);
                
            } else {

                auto insert_p = r.begin();

                for (int j = 0; j < k; j++){
                    insert_p++;
                }
                
                r.insert(insert_p, x);
            }
        } 
        else if (l == 2){
            int k;
            cin >> k;

            if (k > r.size()){
                continue;
            } 
            else {

            auto eat_p = r.begin();

                for (int j = 0; j < k - 1; j++){
                    eat_p++;
                }

                r.erase(eat_p);

            }
        }
    }

    for (int a: r){
        cout << a << endl;
    }
}