Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

****************************************************************************************************

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
  ListNode * res;
  res = NULL;
  if(A == NULL ){return B;}
  if(B == NULL){return A;}
  if(A->val < B->val){res = A; A = A->next;}
  else {res = B; B = B->next;}
  ListNode *track = res;
  while(A != NULL && B != NULL){
      if(A->val < B->val){
          track->next = A;
          track = track->next;
          A = A->next;
      }
      else {
          track->next = B;
          track = track->next;
          B = B->next;
      }
  }
  if(A != NULL)track->next =A;
  else if(B != NULL)track->next = B;
  return res;
}
