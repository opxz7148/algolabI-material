#include <iostream>
#include <stack>
#include <list>

using namespace std;

list<int> pile;
list<int> color;

int n, k;

void print_pile()
{
    for (int rock: pile)
    {
        cout << rock << " ";
    }
    cout << endl;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        color.push_back(x);
    }
    
}

int main()
{
    input();
    for (int rock: color)
    {
        pile.push_front(rock);
        // print_pile();
        int first_color = rock;
        if (pile.size() >= k)
        {
            auto first_pointer = pile.begin();
            bool remove = true;
            for (int i = 0; i < k; i++)
            {
                if (first_color != *first_pointer)
                {
                    remove = false;
                    break;
                }
                first_pointer++;
            }
            if (remove)
            {
                for (int i = 0; i < k; i++)
                {
                    pile.pop_front();
                }
            }
        }
    }
    cout << pile.size() << endl;
}
