1class Solution {
2public:
3    vector<vector<vector<int>>>dp;
4    const int mod = 1e9+7;
5    int h(int i, int j,int sum, vector<vector<int>>&grid, int k){
6        int n = grid.size();
7        int m = grid[0].size();
8
9        sum = sum%k;
10        
11        if(i >= n || j >= m) return 0;
12
13        if(i == n-1 && j == m-1){
14            sum += grid[i][j];
15            if(sum % k == 0) return 1;
16            return 0;
17        }
18
19        if(dp[i][j][sum] != -1) return dp[i][j][sum];
20
21
22        int one = h(i+1, j, sum+grid[i][j], grid,k);
23        int two = h(i, j+1, sum + grid[i][j], grid, k);
24        one = one%mod;
25        two = two%mod;
26
27        return  dp[i][j][sum] = (one + two)%mod;
28    }
29    int numberOfPaths(vector<vector<int>>& grid, int k) {
30        int n = grid.size();
31        int m = grid[0].size();
32
33        dp.assign(n,vector<vector<int>>(m, vector<int>(k+1, -1)));
34        return h(0,0,0,grid,k);
35    }
36};