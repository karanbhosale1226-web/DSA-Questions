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
        if(head==NULL){
            return 0;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=listCount(head);
        vector<ListNode*> ans(k);
        ListNode* temp=head;
        ListNode* head1=head;
        int i=1;
        int next=cnt%k;
        int num=0;
        if(cnt < k){
            while(temp != NULL){
            ans[num] = temp;
            ListNode* forward = temp->next;
            temp->next = NULL;
            temp = forward;
            num++;
            }
            return ans;
        }



        while(temp!=NULL && num<k){
            while(i<cnt/k){
                temp=temp->next;
                i++;
            }
            if(next!=0){
                temp=temp->next;
                next--;
            }
            
            ListNode* forward=temp->next;
            temp->next=NULL;
            ans[num]=head1;
            head1=forward;
            temp=forward;
            num++;
            i=1;
        }
        return ans;

    }
};