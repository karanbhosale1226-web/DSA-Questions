class Solution {
public:
    vector<int> pse(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nse(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top() != n && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ps=pse(heights);
        vector<int> ns=nse(heights);
        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=ns[i]-ps[i]-1;
            int area=heights[i]*width;
            maxArea=max(maxArea,area);

        }
        return maxArea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int area=0;
        vector<int> heights(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            int currentArea=largestRectangleArea(heights);
            if(currentArea > area){
                area=currentArea;
            }
        }
        return area;
        
    }
};