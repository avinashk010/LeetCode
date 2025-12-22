1class Solution {
2public:
3    int maxResult(vector<int>& nums, int k) {
4        // vector<int>dp(nums.size(), INT_MIN);
5        // dp[0] = nums[0];
6        
7        priority_queue<pair<int,int>>pq;
8        pq.push({nums[0],0});
9        int ans = nums[0];
10        
11        for(int i=1; i<nums.size(); i++){
12
13            while(abs(pq.top().second - i) > k){
14                pq.pop();
15            }
16            auto t = pq.top();
17            ans = nums[i] + t.first;
18            pq.push({ans, i});
19        }
20        return ans;
21    }
22};