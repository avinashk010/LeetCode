1class Solution {
2public:
3    vector<vector<vector<long long>>>dp;
4    long long h(int i, int j,int left, vector<vector<int>>& coins){
5        if(i == coins.size()-1 && j == coins[0].size()-1){
6            if(coins[i][j] < 0){
7                if(left>0){
8                    return 0;
9                }
10            }
11            return coins[i][j];
12        }
13        if(i>=coins.size() || j >= coins[0].size()){
14            return INT_MIN;
15        }
16
17        if(dp[i][j][left] != LLONG_MIN) return dp[i][j][left];
18
19    
20        long long ans = INT_MIN;
21        long long one = coins[i][j] + h(i+1, j, left, coins);
22        ans = one;
23        long long two = coins[i][j] + h(i, j+1, left, coins);
24        ans = max(ans, two);
25
26        if(coins[i][j] < 0 && left>0){
27            long long three = h(i+1, j, left-1, coins);
28            long long four = h(i, j+1, left-1, coins);
29            ans = max({ans, three, four});
30        }
31
32        return dp[i][j][left] = ans;
33
34    }
35
36    int maximumAmount(vector<vector<int>>& coins) {
37        dp.assign(coins.size(), vector<vector<long long>>(coins[0].size(), vector<long long>(3, LLONG_MIN)));
38        return h(0,0,2, coins);
39    }
40};