class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,bool> mp(n);
        for(int i=1;i<=n;i++){
            mp[i]=false;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};