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
    int getCount(ListNode* head){
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=getCount(head);
        int i=0;
        ListNode* first=head;
        ListNode* second=head;
        while(i<k-1){
            first=first->next;

            i++;
        }
        i=0;
        while(i<n-k){
            second=second->next;
            i++;
        }
        swap(first->val,second->val);
        return head;
    }
};