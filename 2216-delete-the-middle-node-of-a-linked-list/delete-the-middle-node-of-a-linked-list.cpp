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
    int listCount(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int n=listCount(head);
        int num=n/2;
        int cnt=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(cnt<num){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        return head;
        
    }
};