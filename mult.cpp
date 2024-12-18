#include <iostream>

int a,b;

int mult(int root, int mul)
{
  if(mul == 0) {
    // do something
    return 0;
  } else {
    // do some other things
    return root + mult(root, mul-1);
  }
}

int main()
{
  std::cin >> a >> b;

  std::cout << mult(a,b) << std::endl;
}
