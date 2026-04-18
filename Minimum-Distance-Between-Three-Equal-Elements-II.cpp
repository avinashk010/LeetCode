1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int,vector<int>>mp;
5
6        for(int i =0; i<nums.size(); i++){
7            mp[nums[i]].push_back(i);
8        }
9
10        int ans = INT_MAX;
11
12        for(int i=0; i<nums.size(); i++){
13            auto lb = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i);
14            auto ub = upper_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i);
15
16            if(lb != mp[nums[i]].begin() && ub != mp[nums[i]].end()){
17                lb--;
18                int x = *lb;
19                int y = i;
20                int z = *ub;
21                int val = abs(x-y)+abs(y-z)+abs(x-z);
22                ans = min(ans, val);
23            }
24
25        }
26        if(ans == INT_MAX) return -1;
27        return ans;
28    }
29};