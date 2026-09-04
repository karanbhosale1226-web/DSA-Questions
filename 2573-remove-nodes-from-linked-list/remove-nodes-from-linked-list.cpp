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
    int getLen(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNodes(ListNode* head){
        stack<int>s;
        int n=getLen(head);
        vector<int> arr(n);
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            arr[i]=temp->val;
            temp=temp->next;
        }
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(!s.empty() && curr>=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=s.top();
            }
            s.push(curr);
        }
        
        int i=0;
        while(i<n && ans[i]!=0){
            head=head->next;
            i++;
        }
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(ans[i]!=0){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{

                prev=curr;
                curr=curr->next;
            }
            i++;
        }

        return head;
        
    }
};