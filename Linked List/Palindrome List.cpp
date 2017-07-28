Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes: 
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*************************************************************************************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A == NULL || A->next == NULL) return 1;
    if(A->next->next == NULL){
        if(A->val == A->next->val)return 1;
        else return 0;
    }
   ListNode *temp = A;
   int count = 0;
   while(temp->next != NULL){
       temp = temp->next;
       count++;
   }
   temp = A;
   for(int i=0 ; i<count/2 ; i++){
       temp = temp->next;
   }
   ListNode* current = temp->next , *prev = NULL, *next;
   while(current != NULL){
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
   }
   temp ->next = prev;
   temp = temp->next;
   while(temp != NULL){
       if(A->val != temp ->val)return 0;
       A = A->next;
       temp = temp->next;
   }
   return 1;
}

