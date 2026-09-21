class Solution {
public:
    int mini(vector<int>& arr){
        int min=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                min=arr[i];
            }
        }
        return min;
        
    }
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int max=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 0){
            mp[nums[i]]++;
            if(mp[nums[i]] > max){
                max = mp[nums[i]];
            }
}
        }
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 0 && mp[nums[i]] == max){
                ans.push_back(nums[i]);
            }    
        }
        
        if(ans.empty()){
            return -1;
        }
        int min=mini(ans);
        return min;
    }
};