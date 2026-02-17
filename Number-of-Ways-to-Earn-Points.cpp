1class Solution {
2public:
3    vector<vector<int>>dp;
4    const int mod = 1e9+7;
5    int h(int i, int target, vector<vector<int>>& t){
6        if(i>=t.size()){
7            if(target == 0) return 1;
8            return 0;
9        }
10        if(target == 0) return 1;
11
12        if(dp[i][target] !=-1) return dp[i][target];
13
14        int ans =0;
15        
16        int cost = 0;
17        int one = t[i][1];
18        for(int q = 0; q<=t[i][0]; q++){
19            cost = q*one;
20            if(cost<=target){
21                ans += h(i+1,target-cost, t);
22                ans = ans%mod;
23            }else break;
24        }
25
26        return dp[i][target] = ans;
27
28    }
29    int waysToReachTarget(int target, vector<vector<int>>& types) {
30        dp.assign(types.size(), vector<int>(target+1, -1));
31        return h(0,target,types);
32    }
33};