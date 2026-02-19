1class Solution {
2public:
3    vector<vector<vector<long long>>>dp;
4    long long h(int i,int lastcol, int tar, vector<int>& houses, vector<vector<int>>& cost, int m, int n){
5        if(tar < 0) return INT_MAX;
6    
7        if(i>=m){
8            if(tar != 0) return INT_MAX;
9            return 0;
10        }
11
12        // if(houses[i]!=0){
13        //     if(tar == 0){
14        //         if(lastcol != houses[i]){
15        //             return INT_MAX;
16        //         }
17        //     }
18        // }
19
20        if(dp[i][lastcol][tar] != -1) return dp[i][lastcol][tar];
21
22
23        long long ans = INT_MAX;
24        long long temp = 0;
25        if(houses[i] == 0){
26            for(long long x = 1; x<=n; x++){
27                temp = cost[i][x-1];
28                if(x == lastcol){
29                    temp += h(i+1, x, tar,houses,cost,m,n);
30                }else{
31                    temp += h(i+1, x, tar-1, houses, cost, m, n);
32                }
33                ans = min(temp,ans); 
34            }
35        }else{
36            int color = houses[i];
37
38            if(lastcol == color){
39                temp += h(i+1, color,tar,houses, cost, m, n);
40            }else{
41                temp += h(i+1, color,tar-1,houses, cost, m, n);
42            }
43            ans = min(ans, temp);
44        }
45
46        return dp[i][lastcol][tar] = ans;
47    }
48    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
49
50
51        dp.assign(m, vector<vector<long long>>(n+1, vector<long long>(target+1, -1)));
52
53        long long ans = h(0,0,target,houses,cost,m,n);
54        if(ans >= INT_MAX) return -1;
55        return ans;
56
57    }
58};