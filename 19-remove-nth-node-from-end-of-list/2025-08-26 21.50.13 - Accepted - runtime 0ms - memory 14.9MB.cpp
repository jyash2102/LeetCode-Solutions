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
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int pos=cnt-n+1;
        if(n==cnt){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        cnt=0;
        temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            cnt++;
            if(pos==cnt){
                prev->next=temp->next;
                temp->next=NULL;
                delete(temp);
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};