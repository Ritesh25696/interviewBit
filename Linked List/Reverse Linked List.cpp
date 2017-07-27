Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

****************************************************************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
 ListNode * current = A ,*next, *prev = NULL;
 while(current != NULL){
     next = current->next;
     current->next = prev;
     prev = current;
     current = next;
 }
 A = prev;
 return A;
}
