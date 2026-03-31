1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int l =0;
5        int zero =0;
6        int ans =0;
7
8        for(int r =0; r<nums.size(); r++){
9            if(nums[r] == 0){
10                zero++;
11            }
12
13            if(zero > k){
14                if(nums[l++] == 0){
15                    zero--;
16                }
17            }
18
19            ans = max(ans, r-l+1);
20        }
21
22        return ans;
23    }
24};