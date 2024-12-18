#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;

  ListNode(int val, ListNode* next=0)
    : val(val), next(next) {}
};

int n;
ListNode* first = 0;
ListNode* last = 0;

void read_input()
{
  std::cin >> n;
  for(int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    if(first == 0) {
      first = new ListNode(x);
      last = first;
    } else {
      ListNode* new_node = new ListNode(x);
      last->next = new_node;
      last = new_node;
    }
  }
}

bool is_empty(ListNode* node)
{
  return node == 0;
}

bool is_last(ListNode* node)
{
  return node->next == 0;
}

int list_sum(ListNode* node)
{
  if(is_last(node)) {  

    return node -> val;

  } else {

    int remain_sum = list_sum(node -> next);

    return node -> val + remain_sum;
  }
}

int main()
{
  read_input();
  cout << list_sum(first) << endl;
}