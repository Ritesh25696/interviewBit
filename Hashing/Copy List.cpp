
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

**********************************************************************************************************************************************************************

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A == NULL){
        return NULL;
    }
    
    RandomListNode* head = A;
    RandomListNode* cloned;
    RandomListNode* newHead = new RandomListNode(head->label);
    RandomListNode* curr = head;
    RandomListNode* temp = newHead;
    
    unordered_map<RandomListNode*, RandomListNode*> myMap;
    
    myMap.insert({head, newHead});
    curr = curr->next;
    while(curr != NULL){
        cloned = new RandomListNode(curr->label);
        temp->next = cloned;
        temp = temp->next;
        myMap.insert({curr, cloned});
        curr = curr->next;
    }
    
    curr = A;
    temp = newHead;
    while(curr != NULL){
        if((myMap.find(curr->random)) != myMap.end()){
            myMap[curr]->random = myMap[curr->random];    
        }
        else{
            myMap[curr]->random = NULL;
        }
        curr = curr->next;
    }
    
    return newHead;
}
