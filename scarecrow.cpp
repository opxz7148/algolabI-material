#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int i, n, t;
bool cover[100];
string field;

void input(){
    cin >> n;
    cin >> field;
    for (int i = 0; i < n; i++)
    {
        cover[i] = false;
    }
}

void print_fields(){
    for (int i = 0; i < n; i++)
    {
        char cur = field[i];
        if (cur != '#'){
            if (cover[i]){
                cout << 'x';
                continue;
            }
        }
        cout << cur;
    }
    cout << "\n";
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char cur_field;
        input();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cur_field = field[i];

            if (cur_field == '.'){

                if (!cover[i]){

                    if (i == n - 1){
                        count++;
                    } else {
                        cover[i] = true;
                        cover[i + 1] = true;
                        if (i + 2 <= n - 1){
                            cover[i + 2] = true;
                        }
                        count++;
                    }

                }
            }
            // print_fields();
        }
        cout << "Case " << i + 1 << ": " << count << "\n"; 

    }
}
