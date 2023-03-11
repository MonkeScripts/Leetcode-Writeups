//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//Use the tortoise and hare algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode* tortoise = head;
        ListNode* hare = head->next;
        while(hare&& hare->next){
            if(tortoise == hare) return true;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return false;  
    }
};
