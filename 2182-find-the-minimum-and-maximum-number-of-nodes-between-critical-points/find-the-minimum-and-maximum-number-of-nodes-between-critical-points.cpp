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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2);
        ans[0]=ans[1]=(-1);
        ListNode* prev=head;
        ListNode* curr=head->next;
        int currPosition=1;
        int prevCritical=0;
        int firstCritical=0;
        int minDistance=INT_MAX;
        int maxDistance=INT_MIN;

        while(curr!=NULL && curr->next!=NULL){
            if(((prev->val)<(curr->val) && (curr->val)>(curr->next->val)) || 
                ((prev->val)>(curr->val)&&(curr->val)<(curr->next->val))){
                if(firstCritical==0){
                    firstCritical=currPosition;
                    prevCritical=currPosition;
                }
                else{
                    minDistance=min(minDistance,currPosition-prevCritical);
                    prevCritical=currPosition;
                }
                
            }
            prev=curr;
            curr=curr->next;
            currPosition++;
        }
        if(minDistance!=INT_MAX){
            maxDistance=prevCritical-firstCritical;
            ans[0]=minDistance;
            ans[1]=maxDistance;
        }
        
        return ans;
        
    }
};