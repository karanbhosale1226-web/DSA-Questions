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
    int getLength(ListNode* head){
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    int pow(int a,int b){
        int ans=1;
        for(int i=0;i<b;i++){
            ans=ans*a;
        }
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        int n=getLength(head);
        int arr[n];
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            arr[i]=temp->val;
            temp=temp->next;
        }
        int ans=0;
        int j=0;
        for(int i=n-1;i>=0;i--){
            ans=ans+arr[i]*pow(2,j);
            j++;
        }
        return ans;
    }
};