/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!(head)) return head;
        struct ListNode* current = head;
        struct ListNode* prev = head;
        int length = 0;
        int count = 0;
        // find the total length of the linked list
        while(current){
            current = current->next;
            length ++;
        }
        if(length - n == 0) return head->next;
        current = head;
        // run a while loop that ends when current becomes the node to be deleted
        while(count < length - n && current){
            prev = current;
            current = current->next;
            count ++;
        }
        //bridge the node before the deleted node to the node after deleted node
        prev->next = current->next;
        return head;
    }
};
