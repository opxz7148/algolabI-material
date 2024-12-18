#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200010;

int score[MAX_N];
long p[MAX_N];
vector<int> first_win;
vector<int> first_lose;
vector<int> first_tie;

int n;

// void print_score(){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << score[i][j] << " ";
//         }
//         cout << "\n\n";
//     }
// }

void input(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long pot;
        cin >> pot;
        p[i] = pot;
    }
}

void init(){
    for (int i = 0; i < n; i++)
    {    
        score[i] = 0;   
    }
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    init();

    for (int j = 1; j < n; j++)
    {
        if (p[0] > p[j]){
            score[0] += 2;
            first_win.push_back(j);
        } else if (p[0] < p[j]){
            first_lose.push_back(j);
        } else {
            score[0] += 1;
            first_tie.push_back(j);
        }
    }

    cout << score[0] << "\n";

    for (int i = 1; i < n; i++)
    {
        
            if (p[i] > p[0]){
                score[i] = score[0] + first_tie.size();
                for (int k: first_lose){
                    if (p[k] < p[i]){
                        score[i] += 2;
                    }
                }
                score[i] += 2;
            } else if (p[i] < p[0]){
                score[i] = score[0];
                for (int k: first_win){
                    if (p[k] > p[i]){
                        score[i] -= 2;
                    } else if (p[k] == p[i]){
                        score[i] -= 1;
                    }
                }
                score[i] -= 1;
            } else {
                score[i] = score[0];
            }
        
        cout << score[i] << "\n";
    }
    

}
