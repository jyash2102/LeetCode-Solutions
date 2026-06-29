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
    bool countK(ListNode* head ,int k){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL && cnt<k){
            cnt++;
            temp=temp->next;
        }
        if(cnt==k) return true;
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(countK(head,k)==false) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* front=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            cnt++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};