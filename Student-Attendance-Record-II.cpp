1class Solution {
2public:
3    vector<vector<vector<long long>>>dp;
4    const int mod = 1e9+7;
5    long long h(int i, int l, int ab, int n){
6        if(i >= n) return 1;
7
8        if(dp[i][l][ab] != -1) return dp[i][l][ab];
9
10        long long ans = 0;
11        long long one = h(i+1, 0, ab, n);
12        ans += one;
13        ans = ans%mod;
14
15        if(l < 2){
16            long long two = h(i+1, l+1, ab, n);
17            
18            ans += two;   
19            ans = ans%mod;
20        }
21
22        if(ab < 1){
23            long long three = h(i+1, 0, ab+1, n);
24            ans+=three;
25            ans = ans%mod;
26
27        }
28
29        return dp[i][l][ab] = ans;
30    }
31
32    int checkRecord(int n) {
33        dp.assign(n, vector<vector<long long>>(3, vector<long long>(2, -1)));
34        long long ans = h(0,0,0,n);
35        const int mod = 1e9+7;
36        return ans%mod;
37    }
38};