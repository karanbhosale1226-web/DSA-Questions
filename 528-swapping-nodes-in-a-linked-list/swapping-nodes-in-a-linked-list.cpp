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
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n=getCount(head);
        vector<int> arr(n);
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            arr[i]=temp->val;
            temp=temp->next;
        }
        swap(arr[k-1],arr[n-k]);
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
        
    }
};