#include <iostream>
#include <list>

using namespace std;

int n, m;
list<int> seq;
list<pair<int, int> > shoot;

void input(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        seq.push_back(i);
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        int c, p;
        cin >> c >> p;
        shoot.push_back(make_pair(i, p));
    }
    
}

int main(){
    input();
    
    for (auto s: shoot)
    {
        int num = s.first;
        int pos = s.second;

        for (auto iter = seq.begin(); iter != seq.end(); iter++)
        {
            if (*iter == pos)
            {
                iter++;
                seq.insert(iter, num);
                break;
            }
        }
    }

    for (auto a: seq)
    {
        cout << a << "\n";
    }
}
