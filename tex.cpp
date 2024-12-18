#include <iostream>
#include <string>

using namespace std;

int main()
{
  string st;
  string result = "";
  bool open = false;

  while(getline(cin, st)) {
    for(int i = 0; i < st.length(); i++){
        char c = st[i];
        if (c == '"'){
            if (open){
                result = result + "''";
                open = false;
            } else {
                result = result + "``";
                open = true;
            }
        } else {
            result = result + c;
        }
    }
    cout << result << endl;
  }
}