#include <iostream>
#include <string>
#include <list>

using namespace std;

void print_list(list<string> l){

    cout << "Dream: ";
    for (string a: l){
        cout << a << ", ";
    }
    cout << endl;


}

int main(){

    int n;
    cin >> n;
    
    string action, name;

    list<string> dream;
    dream.push_back("Not in a dream");
    auto cob = dream.begin();

    for (int i = 0; i < n; i++)
    {
        cin >> action;

        if (action == "Sleep"){
            cin >> name;
            cob++;
            if (cob == dream.end()){
                dream.push_back(name);
                cob--;
            } else {
                *cob = name;
            }
            
        } else if (action == "Test"){
            cout << *cob << endl;
        } else if (action == "Kick"){
            if (cob != dream.begin()){
                cob--;
            }
        }
        // print_list(dream);
    }
    
    



}
