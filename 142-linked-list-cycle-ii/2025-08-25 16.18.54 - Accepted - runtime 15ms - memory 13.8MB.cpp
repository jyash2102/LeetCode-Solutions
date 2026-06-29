/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        unordered_map<ListNode*,bool> mp;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()) return temp;
            mp[temp]=true;
            temp=temp->next;
        }
        return NULL;
    }
};