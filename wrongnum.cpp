#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 30;

int table[MAX_N][MAX_N];
int n;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
}

int main()
{
    int wrow = 0;
    int wcol = 0;
    int row_sum[MAX_N];
    int col_sum[MAX_N];
    input();

    // Row sum;
    for (int i = 0; i < n; i++)
    {
        row_sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            row_sum[i] += table[i][j];
        }
    }
    // Col sum
    for (int i = 0; i < n; i++)
    {
        col_sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            col_sum[i] += table[j][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int curr = row_sum[i];
        int next_num = row_sum[(i + 1) % n];
        int next_next_num = row_sum[(i + 2) % n];

        if (curr != next_num)
        {
            if (curr == next_next_num)
            {
                wrow = (i + 1) % n;
                break;
            } 
            else if (next_num == next_next_num)
            {
                wrow = i % n;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int curr = col_sum[i];
        int next_num = col_sum[(i + 1) % n];
        int next_next_num = col_sum[(i + 2) % n];

        if (curr != next_num)
        {
            if (curr == next_next_num)
            {
                wcol = (i + 1) % n;
                break;
            } 
            else if (next_num == next_next_num)
            {
                wcol = i % n;
                break;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << row_sum[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << col_sum[i] << " ";
    // }
    // cout << endl;

    // cout << wrow << " " << wcol << endl;
    
    cout << table[wrow][wcol] << endl;
}
