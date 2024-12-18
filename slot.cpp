#include <iostream>
#include <vector>

using namespace std;
vector<int> slot[4];

void input()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int x;
            cin >> x;
            slot[j].push_back(x);
        }
        
    }
}

int main(){
    input();
    int ans = 0;
    int tmp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    tmp = 0;
                    for (int m = 0; m < 4; m++)
                    {
                        int pos_1 = slot[0][(i + m) % 4];
                        int pos_2 = slot[1][(j + m) % 4];
                        int pos_3 = slot[2][(k + m) % 4];
                        int pos_4 = slot[3][(l + m) % 4];
                        // cout << pos_1 << pos_2 << pos_3 << pos_4 << endl;
                        if (
                            (pos_1 == pos_2) &&
                            (pos_2 == pos_3) &&
                            (pos_3 == pos_4)
                        )
                        {
                            // cout << "*" << slot[0][(i + m + 1) % 4] << slot[1][(j + m + 1) % 4] << slot[2][(k + m + 1) % 4] << slot[3][(l + m + 1) % 4] << endl;
                            tmp++;
                        }
                    }
                    if (tmp > ans)
                    {
                        ans = tmp;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
