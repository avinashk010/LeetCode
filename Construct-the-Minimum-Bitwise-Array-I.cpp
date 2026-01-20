1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int>ans(nums.size(),0);
5
6        for(int i=0; i<nums.size(); i++){
7            if(nums[i] == 2){
8                ans[i] = -1;
9                continue;
10            }
11
12            int num = 1;
13            for(int bit = 1; bit<12; bit++){
14                if((1<<bit) & nums[i]){
15                    num = 1<<bit;
16                }else{
17                    ans[i] = nums[i] - num;
18                    break;
19                }
20            }
21        }
22        return ans;
23
24    }
25};