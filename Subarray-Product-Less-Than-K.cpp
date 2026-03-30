1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4
5        if(k<=1)return 0;
6
7        int ans =0;
8
9        int l =0;
10 
11        
12        long long mul = 1;
13        
14        for(int r=0; r<nums.size(); r++){
15            mul *= nums[r];
16
17            while(mul>=k){
18                mul/=nums[l++];
19            }
20
21            if(r>=l) ans += r-l+1;
22
23        }
24
25        return ans;
26    }
27};