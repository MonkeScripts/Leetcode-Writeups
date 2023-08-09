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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* result = nullptr;
        //finding the head of the linked list
        if(list1->val < list2->val){
            result = list1;
            list1 = list1->next;                
        }
        else{
            result = list2;
            list2 = list2->next;
        }
        ListNode* Final = result; //Final points to the head of the list
        //result does all the dirty work
        while(list1 || list2){
            //if list2 does not exist anymore or list1 val <= list 2 val
            if(!list2 || list1 &&(list1->val <= list2->val)){
                result->next = list1;
                list1 = list1->next;                
            }
            else{
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next;
        }
        return Final;
    }
};
