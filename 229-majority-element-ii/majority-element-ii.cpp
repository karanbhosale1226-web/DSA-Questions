class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if((mp[nums[i]])>(n/3) && find(ans.begin(), ans.end(), nums[i]) == ans.end()){
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};