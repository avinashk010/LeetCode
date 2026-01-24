1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int ans = 0;
6
7        for(int i=0; i<((int)nums.size()/2); i++){
8            ans = max(ans , nums[i] + nums[nums.size()-1-i]);
9        }
10        return ans;
11    }
12};