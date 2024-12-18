#include <iostream>
using namespace std;

pair<int, int> get_height_width(string p){
    if (p == "-"){
        return pair<int, int>(1, 4);
    } else if (p == "i"){
        return pair<int, int>(4, 1);
    } else if (p == "o"){
        return pair<int, int>(2, 2);
    } else {
        return pair<int, int>(0, 0);
    }
}

void p_arr(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    // col[n] will return height of n column
    int col[10] = {0};
    int n; 
    int max = 0;

    cin >> n;

    for (int i = 0; i < n; i++){

        string p;
        int l_col;
        int h;
        int w;

        // Var to store max height of each piece
        int mrn = 0;

        // Get both input
        cin >> p;
        cin >> l_col;

        // Get pieces height and width
        pair<int, int>w_h = get_height_width(p);
        h = w_h.first;
        w = w_h.second;


        // Find hight point that piece will drop on
        for (int j = l_col-1; j < l_col-1 + w; j++){
            if (col[j] > mrn){
                mrn = col[j];
            }
        }

        // Add piece height into original height
        mrn = mrn + h;

        // Update new height into game field 
        for (int j = l_col-1; j < l_col-1 + w; j++){
            col[j] = mrn;
        }

        if (mrn > max){
            max = mrn;
        }

        // p_arr(col, 10);
    }

    cout << max << endl;
}

