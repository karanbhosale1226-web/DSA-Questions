class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        unordered_map<int,int> check;

        for(auto x : mp){
            check[x.second]++;
        }

        for(auto x : check){
            if(x.second > 1){
                return false;
            }
        }

        return true;
    }
};