#include <iostream>
#include <list>

using namespace std;

int n, k;


int main(){
    cin >> n >> k;
    bool burn[n][n];

    list< pair<int, int> > new_fire;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            burn[i][j] = false;
        }
    }

    for (int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;
        // adjust to 0 index
        r--;
        c--;
        burn[r][c] = true;
        new_fire.push_back(pair<int, int>(r, c));
    }

    bool all_burn = false;
    int t = 0;

    while (!all_burn){

        // cout << "\nt: " << t << "\n\n";

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //             if (burn[i][j]){
        //                 cout << "# ";
        //             } else {
        //                 cout << "* ";
        //             }
        //         }
        //     cout << "\n\n";
        // }

        t++;
        all_burn = true;
        int new_fire_count = new_fire.size();
        for (int i = 0; i < new_fire_count; i++){

            auto check_fire = new_fire.front();
            new_fire.pop_front();
            int check_r = check_fire.first;
            int check_c = check_fire.second;

            if (check_r < n - 1){
                if (!burn[check_r + 1][check_c]){
                    burn[check_r + 1][check_c] = true;
                    new_fire.push_back(pair<int, int>(check_r + 1, check_c));
                    all_burn = false;
                    // cout << check_r + 1 << ","<< check_c << " is burn from " << check_r << ","<< check_c << endl;
                }
            }
            if (check_r > 0){
                if (!burn[check_r - 1][check_c]){
                    burn[check_r - 1][check_c] = true;
                    new_fire.push_back(pair<int, int>(check_r - 1, check_c));
                    all_burn = false;
                    // cout << check_r - 1 << ","<< check_c << " is burn from " << check_r << ","<< check_c << endl;
                }
            }
            if (check_c < n - 1){
                if (!burn[check_r][check_c + 1]){
                    burn[check_r][check_c + 1] = true;
                    new_fire.push_back(pair<int, int>(check_r, check_c + 1));
                    all_burn = false;
                    // cout << check_r<< ","<< check_c + 1<< " is burn from " << check_r << ","<< check_c << endl;
                }
            }
            if (check_c > 0){
                if (!burn[check_r][check_c - 1]){
                    burn[check_r][check_c - 1] = true;
                    new_fire.push_back(pair<int, int>(check_r, check_c - 1));
                    all_burn = false;
                    // cout << check_r<< ","<< check_c - 1<< " is burn from " << check_r << ","<< check_c << endl;
                }
            }
        }
    }

    cout << t - 1<< "\n";
}
