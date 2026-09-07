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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp=head;
        while(temp!=NULL){
            mp[temp->val]=0;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        
        while(head!=NULL && mp[head->val]>1){
            head=head->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(mp[curr->val]>1){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;

    }
};