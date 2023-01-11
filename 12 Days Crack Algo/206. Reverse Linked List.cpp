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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* current= head->next;
        ListNode* prev = head;
        prev->next =  nullptr;
        //ensures head points to null when it flips
        while(current){
            //create a variable to store the current pointer so that we are able to iterate through the list
            ListNode* next = current->next;
            //link current.next to prev
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
