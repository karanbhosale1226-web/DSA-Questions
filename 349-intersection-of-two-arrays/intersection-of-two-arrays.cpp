class Solution {
public:
    bool ispresent(int n,vector<int> ans){
        for(int i=0;i<ans.size();i++){
            if(n==ans[i]){
                return true;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    if(!ispresent(nums1[i],ans)){
                        ans.push_back(nums1[i]);
                    }
                }
            }
        }
        return ans;
        
    }
};