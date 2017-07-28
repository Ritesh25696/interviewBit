Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

*********************************************************************************************************************************

ListNode* reverse(ListNode *A){
    ListNode* current = A,*prev=NULL , *next;
    while(current != NULL){
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
    }
    A = prev;
    return A;
} 
 
ListNode* Solution::reverseBetween(ListNode* A, int n, int m) {
 ListNode *temp1 = A ,*temp2, *temp3= A , *temp4;
 
 for(int i=0 ;i<n-2 ; i++)temp1 = temp1->next;
 temp2 = temp1->next;
 if(n == 1)temp2 = temp1;
 for(int i=0 ; i<=m-2 ; i++){
    temp3 = temp3->next; 
 }
 temp4 = temp3->next;
 temp3->next = NULL;
 if(n>1){
 temp1->next = reverse(temp2);}
 else{
    A =  reverse(temp2);
    temp1 = A;
 }
 while(temp1->next != NULL)temp1=temp1->next;
 temp1->next = temp4;
 return A;
}
