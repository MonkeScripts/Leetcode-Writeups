//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* current = head->next;
        ListNode* prev= head;
        ListNode* result = prev;
        while(current){
            if(current->val == prev->val){
                prev->next = current->next;
                //change current to start from prev
                current = prev;
            }
            prev = current;
            current = current->next;
        }
        return result;    
    }
};
