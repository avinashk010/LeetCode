1class Solution {
2public:
3    vector<int>dp;
4    int h(int i, int sign, vector<int>&nums){
5        if(i>=nums.size()) return 0;
6
7        if(dp[i] != -1) return dp[i];
8
9        int one = 0;
10        int ans = 0;
11        if(sign == 1){ //bda chahiye
12            if(i==0 ||nums[i] > nums[i-1]){
13                one = 1 + h(i+1, 2, nums);
14            }else{
15                one = 0 + h(i+1, 1, nums);
16            }
17            ans = max(ans, one);
18        }else{ // chhota chahiye
19            if(i==0 ||nums[i] < nums[i-1]){
20                one = 1 + h(i+1, 1, nums);
21            }else{
22                one = 0 + h(i+1, 2, nums);
23            }
24            ans = max(ans, one);
25        }
26
27        int three = h(i+1, sign, nums);
28
29        ans = max(ans, three);
30
31        return dp[i] = ans;
32    }
33
34    int wiggleMaxLength(vector<int>& nums) {
35        dp.assign(nums.size(), -1);
36        int one = h(0,1,nums);
37
38        dp.assign(nums.size(), -1);
39        int two = h(0,2, nums);
40
41
42
43        return max(one,two);
44    }
45};