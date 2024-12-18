#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n = 0;
vector<int> a;
vector<int> l;
vector<int> parent;

void input(){
    int x;
    while(cin >> x){
        a.push_back(x);
        n++;
    }
}

int main(){
    input();

    int best_len = 0;
    int best_index = -1;

    for (int i = 0; i < n; i++)
    {
        int max = 0;
        int p = -1;

        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && l[j] >= max)
            {
                max = l[j];
                p = j;
            }
        }
        l.push_back(max + 1);
        parent.push_back(p);

        if (l[i] >= best_len)
        {
            best_len = l[i];
            best_index = i;
        }
    }
    cout << best_len;
    cout << "\n-\n";
    stack<int> ans;
    
    int index = best_index;

    while(index != -1)
    {
        ans.push(a[index]);
        index = parent[index];
    } 

    while(!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
}
