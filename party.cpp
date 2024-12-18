#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> leds[2000];
pair<int, int> max_leds[2000];
pair<int, int> last_leds[2000];

int n;

void input()
{
    cin >> n;
    int y, c;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> c;
        leds[i] = make_pair(y, c);
    }
    
}

void init()
{
    max_leds[0] = pair<int, int>(1, 0);
    last_leds[0] = leds[0];
}

int main()
{
    input();
    init();
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        max_leds[i] = pair<int, int>(1, 0);
        last_leds[i] = leds[i];

        for (int j = i - 1; j >= 0; j--)
        {
            int this_y = last_leds[i].first;
            int this_c = last_leds[i].second;
            int this_max_led = max_leds[i].first;

            int last_y = last_leds[j].first;
            int last_c = last_leds[j].second;
            int last_max_led = max_leds[j].first;
            int order = max_leds[j].second;

            if 
            (
                this_c == last_c ||
                last_max_led + 1 <= this_max_led ||
                (order == -1 && this_y > last_y) ||
                (order == 1 && this_y < last_y) 
            ){continue;}

            if (order != 0)
            {
                max_leds[i].second = order;
            } 
            else
            {
                if (this_y < last_y)
                {
                    max_leds[i].second = -1;
                }
                else if (this_y > last_y)
                {
                    max_leds[i].second = 1;
                }
                else
                {
                    max_leds[i].second = 0;
                }
            }
            max_leds[i].first = last_max_led + 1;
        }
        
        if (max_leds[i].first > ans)
        {
            ans = max_leds[i].first;
        }
    }
    cout << ans << "\n";
}
