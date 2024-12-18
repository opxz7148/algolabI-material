#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> l){

    for (int a: l){
        cout << a << " ";
    }

}

int main(){
    int n, m, t;
    cin >> n >> m;

    list<int> q(n, 0);

    auto angel = q.begin();

    for (int i = 0; i < m; i++){
        cin >> t;
        if (t == 0){
            angel = q.begin();
        } else if (t == 1){
            angel++;
        } else if (t == 2){
            if (angel == q.end()){
                q.push_back(0);
            } else {
                angel++;
                q.insert(angel, 0);
                angel--;
                angel--;
            }
        } else if (t == 3){
            int x;
            cin >> x;
            *angel = *angel + x;
        }
    }
    print_list(q);
}
