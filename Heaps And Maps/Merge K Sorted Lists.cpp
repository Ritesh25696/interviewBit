Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

****************************************************************************************************

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if(A.size() == 1)return A[0];
    map <int, vector<ListNode*>> mymap;
    for(int i=0 ; i<A.size() ; i++){
        ListNode* temp = A[i];
        while(temp != NULL){
            mymap[temp->val].push_back(temp);
            temp = temp->next;
        }
    }
    ListNode *head = NULL , *temp;
     for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        for(int i=0 ; i<it->second.size() ; i++){
            if(head == NULL)
            {head = it->second[i];
            temp = head;
            temp->next = NULL;}
            else{
                temp ->next = it->second[i];
                temp = temp->next;
                temp->next = NULL;
            }
        }
    }
    return head;
}
