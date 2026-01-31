1class Solution {
2public:
3    int h(int b, vector<int>&nums){
4        vector<int>v;
5
6        for(int i =0; i<nums.size(); i++){
7            if((1<<b) & nums[i]){
8                if(v.size() == 0){
9                    v.push_back(nums[i]);
10                }else{
11                    if(nums[i] > v.back()){
12                        v.push_back(nums[i]);
13                        continue;
14                    }
15                    int it = lower_bound(v.begin(),v.end(), nums[i])-v.begin();
16                    v[it] = nums[i];
17                }
18            }
19        }
20
21        return (int)v.size();
22    }
23    int longestSubsequence(vector<int>& nums) {
24        int ans = 0;
25        for(int i=0; i<32; i++){
26            ans = max(ans, h(i,nums));
27            
28        }
29
30        return ans;
31
32    }
33};