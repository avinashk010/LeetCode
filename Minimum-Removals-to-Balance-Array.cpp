1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int ans = INT_MAX;
6        for(int i=0; i<nums.size(); i++){
7            int back = i;
8            int up = upper_bound(nums.begin(),nums.end(),1LL*nums[i]*k)-nums.begin();
9            up--;
10            int front = nums.size()-up-1;
11            ans = min(ans, back+front);
12        }
13
14        return ans;
15    }
16};