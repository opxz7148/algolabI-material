#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, p, q;
vector<int> egg_weight;

void input(){
    int w;
    cin >> n >> p >> q;
    egg_weight.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        egg_weight.push_back(w);
    }
    
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        input();
        sort(egg_weight.begin(), egg_weight.end());

        int weight_in_bowl = 0;
        int num_egg_in_bowl = 0;
        for(int egg: egg_weight){
            if (weight_in_bowl + egg <= q && num_egg_in_bowl + 1 <= p){
                weight_in_bowl += egg;
                num_egg_in_bowl++;
            }
        }
        cout << "Case " << i + 1 << ": " << num_egg_in_bowl << "\n"; 
    }
    
}
