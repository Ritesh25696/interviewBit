Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

***********************************************************************************************************************************

ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *slow = A , *fast = A;
    bool iscycle = false;
    while(fast !=NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            iscycle = true;
           break;
        }

    }
    if(!iscycle)return NULL;
    fast = A;
    while(fast != slow){
        fast=fast->next;slow=slow->next;
    }
    return fast;
}
