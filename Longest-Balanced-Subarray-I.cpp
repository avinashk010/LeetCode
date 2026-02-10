1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        int ans =0;
5        for(int i=0; i<nums.size(); i++){
6            set<int>od;
7            set<int>ev;
8            for(int j = i; j<nums.size(); j++){
9                if(nums[j]&1){
10                    od.insert(nums[j]);
11                }else{
12                    ev.insert(nums[j]);
13                }
14                if(od.size() == ev.size()){
15                    ans = max(j-i+1,ans);
16                }
17            }
18            od.clear();
19            ev.clear();
20        }
21        return ans;
22    }
23};