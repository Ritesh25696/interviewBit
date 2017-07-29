You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

**************************************************************************************************************************

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
  ListNode * res = NULL , *start;
  int carry = 0;
  string check = "";
  while(A != NULL && B != NULL){
      int sum = A->val + B->val + carry;
      carry = sum/10;
      ListNode * temp = new ListNode(sum%10);
      check += to_string(sum%10);
      if(res == NULL){res = temp;start=temp; }
      else{res->next = temp; res = res->next;}
      A= A->next;
      B = B->next;
  }
  while(A != NULL){
      int sum = carry+A->val;
      carry = sum/10;
      ListNode * temp = new ListNode(sum%10);
      check += to_string(sum%10);
      res->next = temp; res = res->next;
      A = A->next;
  }
   while(B != NULL){
      int sum = carry+B->val;
      carry = sum/10;
      ListNode * temp = new ListNode(sum%10);
      check += to_string(sum%10);
      res->next = temp; res = res->next;
      B = B->next;
  }
  if(carry != 0){
     check += to_string(carry);
    ListNode * temp = new ListNode(carry);  
    res->next = temp; res = res->next;
    carry = 0;
  }
    reverse(check.begin() , check.end());
  int st = 0;
  while(check[st] == '0' ){
    st++;
  }
  if(st == 0 )return start;
  res = start;
  for(int i=0 ; i<check.length()-st-1 ; i++){
    res = res->next;
  }
  res->next = NULL;
  return start;
}
