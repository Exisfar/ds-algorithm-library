#include <iostream>
#include "data_structure.h"

int main() {
  ListNode *head = new ListNode(1);

  bool has_cycle = ListNode::hasCycle(head);
  int middle_value = ListNode::getMiddle(head);

  std::cout << "Has cycle: " << has_cycle << std::endl;
  std::cout << "Middle value: " << middle_value << std::endl;

  return 0;
}