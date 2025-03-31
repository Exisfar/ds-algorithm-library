#include "data_structure.h"

/* 下面这种注释叫做Doxygen注释 */

/**
 * @brief Detects if a linked list has a cycle.
 *
 * @details Usually use the Floyd's Cycle Detection Algorithm (Fast and Slow
 * Pointers)
 *
 * @param head Pointer to the head of the linked list.
 * @return true if there is a cycle, false otherwise.
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
bool ListNode::hasCycle(ListNode *head) {
  if (!head || !head->next) {
    return false; // No cycle if the list is empty or has only one node
  }

  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next) {
    slow = slow->next;       // Move slow pointer by 1 step
    fast = fast->next->next; // Move fast pointer by 2 steps

    if (slow == fast) {
      return true; // Cycle detected
    }
  }

  return false; // No cycle found
}

/**
 * @brief Finds the middle element of a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @return The value of the middle node.
 */
int ListNode::getMiddle(ListNode *head) {
  if (!head->next) {
    return head->val;
  }

  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->val;
}

ListNode *ListNode::getIntersectionNode(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode *> visited;
  ListNode *p = headA, *q = headB;

  while (p) {
    visited.insert(p);
    p = p->next;
  }

  while (q) {
    if (visited.count(q)) {
      return q;
    }
    q = q->next;
  }
  return nullptr;
}

ListNode *ListNode::reverseList(ListNode *head) {
  ListNode *p = nullptr;
  ListNode *q = head;
  while (q) {
    ListNode *tmp = q;
    q = q->next;
    tmp->next = p;
    p = tmp;
  }
  return p;
}
