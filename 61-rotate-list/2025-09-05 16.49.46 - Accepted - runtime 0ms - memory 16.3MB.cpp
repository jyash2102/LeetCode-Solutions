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
    ListNode* Reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead=Reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* ReverseK(ListNode* head, int a,int r){
        if(head==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* front=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<a){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            cnt++;
        }
        head->next=ReverseK(curr,r,0);
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head; 
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int r=k%n;
        if(r==0) return head;
        ListNode* newhead1=ReverseK(head,(n-r),r);
        ListNode* newhead2=Reverse(newhead1);
        return newhead2;
    }
};