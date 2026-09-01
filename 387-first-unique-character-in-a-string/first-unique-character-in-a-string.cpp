class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<int> q;
        int ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mp[ch]++;
            q.push(i);
            while(!q.empty() && mp[s[q.front()]]>1){
                q.pop();
            }
        }
        if(q.empty()){
            return -1;
        }

        return q.front();

        
    }
};