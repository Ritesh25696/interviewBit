Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

********************************************************************************************************************************************************************************************************

ListNode* reverse(ListNode *A){
    ListNode *cur = A , *prev = NULL , *next;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev= cur;
        cur = next;
    }
    A = prev;
    return A;
}
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B < 2)return A;
    ListNode * temp1 = A , *prev = NULL , *temp3 , *temp2;
    int cur =0;
    while(temp1 != NULL){
       if(prev == NULL){
            temp2 = temp1;
            for(int i=1 ; i<B ; i++){
                temp1 = temp1->next;
            }
            temp3 = temp1->next;
                temp1->next = NULL;
                A = reverse(temp2);
                prev= temp2;
                temp2->next = temp3;
                temp1 = temp3;
        }
        else{
            temp1 = temp3;
            temp2 = temp3;
            for(int i=1 ; i<B ; i++){
                temp1 = temp1->next;
            }
            temp3 = temp1->next;
            temp1->next = NULL;
            prev->next = reverse(temp2);
            prev = temp2;
            temp2->next = temp3;
            temp1 = temp3;
        }
    }
   return A;
}
