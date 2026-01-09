1class Solution {
2public:
3    vector<vector<long long>>dp;
4    long long h(int i, int j, vector<int>&a, vector<int>&b){
5        if(i > a.size()-1 || j > b.size()-1){
6            return INT_MIN;
7        }
8
9        if(dp[i][j] != -1) return dp[i][j];
10        
11    
12        long long four = a[i] * b[j];
13
14        long long  one = (a[i] * b[j]) + h(i+1, j+1, a, b);
15
16        long long two = h(i, j+1, a,b);
17
18        long long three = h(i+1, j, a,b);
19
20        return dp[i][j] = max({one, two, three, four});
21    }
22    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
23        dp.assign(nums1.size(), vector<long long>(nums2.size(), -1));
24        return h(0,0, nums1, nums2);
25    
26    }
27};