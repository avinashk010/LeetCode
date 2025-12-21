1class Solution {
2public:
3    int minSwaps(vector<int>& nums, vector<int>& f) {
4        map<int,int>mp;
5       
6        int tot = 0;
7        for(int i=0; i<nums.size(); i++){
8            if(nums[i] == f[i]){
9                tot++;
10                mp[nums[i]]++;
11            }
12        }
13        int maxi_ele= -1;
14        int maxi = -1;
15        for(auto e : mp){
16            if(e.second > maxi){
17                maxi = e.second;
18                maxi_ele = e.first;
19            }
20        }
21        // cout<<maxi<<" "<<tot;
22        if(maxi <= tot/2){
23            if(tot%2 == 0){
24                return tot/2;
25            }
26            if(tot&1){
27                return ((tot-3)/2) + 2;
28            }
29        }
30
31        int ans = tot - maxi;
32        int remain = maxi - ans;
33
34        int capable = 0;
35        for(int i =0; i<nums.size(); i++){
36            if(f[i] != maxi_ele && nums[i] != f[i] && nums[i] != maxi_ele){
37                capable++;
38            }
39        }
40        // cout<<capable;
41        if(capable >= remain){
42            return ans+ remain;
43        }
44        return -1;
45    }
46};