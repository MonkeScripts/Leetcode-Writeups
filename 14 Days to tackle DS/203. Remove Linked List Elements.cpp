//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head && head->val == val){
            head = head->next;
        }
        ListNode* current = head;
        ListNode* prev = head;
        while(current){
            if(current->val == val){
                prev ->next = current->next;
                //reset the current to start from prev so it follows the deletion
                current= prev;
            }
            //standard way to iterate the pointers
            prev = current;
            current = current -> next;
        }
        return head;
    }
};
