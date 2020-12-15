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
        ListNode* first= new ListNode; ListNode* second= new ListNode; ListNode* third= new ListNode;
        if(head==NULL or head->next==NULL) return head;
        if(head->next->next == NULL){
            first=head; second=head->next;
            head->next=NULL; second->next=head; return second;
        }
        first=head; second=head->next; third=head->next->next;
        first->next=NULL;
        
        while(third->next != NULL){
            second->next=first; first=second; second=third; third=third->next;
        }
        third->next=second;
        second->next = first;
        return third;
    }
};