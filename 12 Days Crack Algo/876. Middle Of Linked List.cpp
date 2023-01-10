// somewhat akind to tortoise and hare algo
//2 pointers with 1 pointer going twice as fast as the other
//when the fast pointer reaches the end, the slow pointer would reach the middle
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
