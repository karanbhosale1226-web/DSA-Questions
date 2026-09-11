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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        while(mp[head->val]!=0){
            head=head->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            if(mp[curr->val]!=0){
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