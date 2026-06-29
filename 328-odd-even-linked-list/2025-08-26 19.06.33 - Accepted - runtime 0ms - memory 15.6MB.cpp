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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* temp=head->next;
        ListNode* even=head->next;
        while(odd->next!=NULL && odd->next->next!=NULL){
            if(odd->next==NULL){
                temp->next=NULL;
                break;
            }
            odd->next=temp->next;
            odd=temp->next;
            if(temp->next==NULL){
                odd->next=NULL;
                break;
            }
            temp->next=odd->next;
            temp=odd->next;
        }
        odd->next=even;
        return head;
    }
};