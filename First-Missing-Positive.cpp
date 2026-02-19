1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int upto = nums.size();
5        for(int i=0; i<nums.size(); i++){
6
7            while(nums[i] != i+1){
8
9                int val = nums[i];
10                
11                if(val > upto) break;
12                if(val <= 0) break;
13                if(val == nums[val-1]) break;
14                swap(nums[val-1], nums[i]);
15            }
16
17        }
18   
19
20        // for(int i=0; i<nums.size(); i++){
21        //     cout<<nums[i]<<" ";
22        // }
23
24        for(int i=0; i<nums.size(); i++){
25            if(nums[i] != i+1){
26                return i+1;
27            }
28        }
29        return upto+1;
30    }
31};