#include <iostream>
using namespace std;

struct person
{
    /* data */
    int val;
    person* p;
    person* b;
};

person _ = person();

int main(){

    int n,k;
    
    // Pointer to current person
    person* c = nullptr;

    // Pointer to previous person
    person* bc = nullptr;

    // Pointer to last person
    person* l = nullptr;

    // Input n and k
    cin >> n >> k;

    // Create table member from last person
    for(int i = n; i > 0; i--){

        person* new_p = new person();
        new_p->val = i;
        new_p->p = c;
        c = new_p;

        if (i == n){
            l = c;
        }        

    }

    // Let last person point to first person
    l -> p = c;
    bc = l;

    while (n > 1) {

        for (int i = 1; i < k; i++){
            c = c -> p;
            bc = bc -> p;
        }

        // Let the Kth person introduce and leave the table
        // Let previous person point to next person
        bc -> p = c -> p;
        
        // Move c to point to next person 
        c = bc -> p;
        n--;
    }
    cout << c -> val << endl;
}