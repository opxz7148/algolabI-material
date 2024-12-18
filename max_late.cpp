#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > jobs;

bool sortByDeadline(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return a.first < b.first;
}


void input(){
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        jobs.push_back(pair<int, int>(c, d));
    }
}

int main(){
    input();
    sort(jobs.begin(), jobs.end(), sortByDeadline);

    int total_day = 0;
    int total_fee = 0;

    for(auto job: jobs){
        total_day += job.second;
        if (total_day > job.first + 10){
            int this_fee = (total_day - (job.first + 10)) * 1000;
            if (this_fee > total_fee){
                total_fee = this_fee;
            }
        }
    }
    cout << total_fee << "\n";
}