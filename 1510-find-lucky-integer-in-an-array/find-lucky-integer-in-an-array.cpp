class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==arr[i]){
                if(arr[i]>ans){
                    ans= arr[i];
                }
            }
        }
        return ans;
        
    }
};