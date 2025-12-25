1class Solution {
2public:
3    int maxSubarrays(vector<int>& nums) {
4        int mini = nums[0];
5        for(int i=1; i<nums.size(); i++){
6            mini = (mini & nums[i]);
7        }
8        if(mini > 0) return 1;
9        int ans =0;
10        int now = nums[0];
11        int i =1;
12        while(i<nums.size()){
13            if(now == mini){
14                ans++;
15                now = nums[i];
16                i++;
17                continue;
18            }else{
19                now = now & nums[i];
20                i++;
21            }
22        }
23        // cout<<mini<<endl;
24        // cout<<now<<endl;
25        if(now == mini){
26            ans++;
27        }
28        return ans;
29    }
30};