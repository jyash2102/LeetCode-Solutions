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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int cnt=0;
        int node=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        node=(cnt/2)+1;
        cnt=0;
        temp=head;
        while(temp!=NULL){
            cnt++;
            if(cnt==node) return temp;
            temp=temp->next;
        }
        return NULL;
    }
};