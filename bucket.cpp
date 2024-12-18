#include <iostream>
#include <vector>

using namespace std;

int bucket[5];
vector<int> jar;

void print_bucket()
{
    for (int i = 0; i < 5; i++)
    {
        cout << bucket[i] << " ";
    }
    cout << "\n";
    
}

void init()
{
    for (int i = 0; i < 5; i++)
    {
        bucket[i] = 0;
    }
}

void input()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    { 
        int x;
        cin >> x;
        jar.push_back(x);
    }
}

int min_index()
{
    int index = 0;
    int water = 2001;
    for (int i = 0; i < 5; i++)
    {
        if (bucket[i] < water)
        {
            index = i;
            water = bucket[i];
        }
    }
    return index;
}

int main()
{ 
    init();
    input();
    int tank = 0;
    
    for (int j: jar)
    {
        int index = min_index();
        if (bucket[index] + j >= 1000)
        {
            tank += 1000;
            bucket[index] = 0;
        } 
        else
        {
            bucket[index] += j;
        }
        // print_bucket();
    }
    cout << tank << "\n";
    
}
