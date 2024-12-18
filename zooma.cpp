#include <iostream>
#include <list>

using namespace std;

// Max ball's number
const int MAX_BALL_NUM = 200000;

 // Crate list to hold the line
list<int> line;
    
// Array to hold that are number already exist in the list or not
bool in_list_check[MAX_BALL_NUM];


void print_list(list<int> l){

    cout << "List: ";
    for (int a: l){
        cout << a << " ";
    }
    cout << endl;

}


void init(){
    for(int i = 0; i < MAX_BALL_NUM; i++){
        in_list_check[i] = false;
    }
}

void check_and_push_front(int a){

    // If this number doesn't exist just put it in
    if (!in_list_check[a]){
        line.push_front(a);
        in_list_check[a] = true;
    } 

    // If this number already exist delete it from front.
    else {
        int tmp;
        while (tmp != a){

            tmp = *line.begin();
            in_list_check[tmp] = false;
            line.pop_front();

        }
    }
}

void check_and_push_back(int a){

    // If this number doesn't exist just put it in
    if (!in_list_check[a]){
        line.push_back(a);
        in_list_check[a] = true;
    } 

    // If this number already exist delete it from front.
    else {
        int tmp;
        while (tmp != a){
            auto tmp2 = line.end();
            tmp2--;
            tmp = *tmp2;
            in_list_check[tmp] = false;
            line.pop_back();

        }
    }
}

int main(){

    init();

    // Get number of action
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        // Get action type and ball number
        int d, a;
        cin >> d >> a;

        switch (d){
            case 0: 
                check_and_push_front(a);
                break;

            case 1: 
                check_and_push_back(a);   
                break;
        }
        // print_list(line);
    }
    cout << line.size();
}
