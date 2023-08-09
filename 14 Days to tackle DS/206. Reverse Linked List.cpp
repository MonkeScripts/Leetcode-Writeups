class Solution {
public:
  ListNode* reverseList(ListNode* head) {
      //base case
      if(!head||!head->next) return head;
      //recursive case
      //way to keep returning the head
      ListNode* res = reverseList(head->next);
      //reverses linked list 
      //head.next points to head
      head->next->next = head;
      //remove existing connection
      head->next = nullptr;
      return res;           
    }
    ListNode* _reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* current = head->next;
        ListNode* prev = head;
        prev->next = nullptr;
        while(current){
            ListNode* nextStep =  current->next;
            current->next = prev;
            prev = current;
            current = nextStep;
        }
        return prev;
    }
};
