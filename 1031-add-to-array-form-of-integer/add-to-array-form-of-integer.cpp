class Solution {
public:
    void reverse(vector<int>& nums){
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        vector<int> ans;
        while(i>=0 || k!=0){
            if(i>=0){
                k=k+num[i];
                i--;
            }
            ans.push_back(k%10);
            k=k/10;
        }
        reverse(ans);
        return ans;
        
    }
};