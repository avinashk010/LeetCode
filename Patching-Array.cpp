1class Solution {
2public:
3    int minPatches(vector<int>& nums, int n) {
4        long long need = 1;
5        int ans = 0;
6        int i =0;
7
8        while(need<=n){
9            if(i<nums.size() && nums[i] <= need){
10                need += nums[i];
11                i++;
12            }else{
13                ans++;
14                need *=2;
15            }
16        }
17
18        return ans;
19    }
20};