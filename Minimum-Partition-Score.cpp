1class Solution {
2public:
3
4    long long INF = 1e15;
5    vector<vector<long long>>dp;
6    long long h(int i, int k, vector<int>&nums){
7        if(nums.size() - i < k+1){
8            return INF;
9        }
10        if(k==0){
11            long long adds=0;
12            for(int x = i; x<nums.size(); x++){
13                adds+=nums[x];  
14            }
15            __int128 t = (__int128)adds*(adds+1)/2;
16            return (long long)t;
17        }
18        
19        if(i>=nums.size()){
20            
21            return INF;
22        }
23        if(dp[i][k] != -1) return dp[i][k];
24
25        long long one = 0;
26        long long sum =0;
27
28        long long nowscore =0;
29        long long temp = 0;
30        long long ans = INF;
31        for(int x = i; x<=nums.size()-k-1; x++){
32            sum += nums[x];
33            nowscore = (sum * (sum+1) / 2);
34            if(nowscore >= ans) break;
35            one = h(x+1, k-1, nums);
36            temp = nowscore+one;
37            ans = min(ans,temp);
38        }
39        
40        return dp[i][k] = ans; 
41    }
42    
43    long long minPartitionScore(vector<int>& nums, int k) {
44        dp.assign(nums.size(), vector<long long>(k+1,-1));
45        return h(0,k-1,nums);
46 
47    }
48};