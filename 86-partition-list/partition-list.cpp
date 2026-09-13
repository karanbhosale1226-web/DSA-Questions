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
    int listCnt(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                cnt++;
            }
            temp=temp->next;
        }
        temp=head;
        int n=listCnt(head);
        vector<int> arr(n);
        int i=0;
        while(temp!=NULL && i<cnt){
            if(temp->val<x){
                arr[i]=temp->val;
                i++;
            }
            temp=temp->next;
        }
        i=cnt;
        temp=head;
        while(temp!=NULL && i<n){
            if(temp->val>=x){
                arr[i]=temp->val;
                i++;
            }
            temp=temp->next;
        }
        temp=head;
        i=0;
        while(temp!=NULL){
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};