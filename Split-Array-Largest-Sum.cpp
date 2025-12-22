1class Solution {
2public:
3    pair<bool,int> h(vector<int>&nums, int k, int m){
4        k--;
5        int sum = nums[0];
6        int kk =0;
7        int maxi = -1;
8        for(int i=1; i<nums.size(); i++){             
9            if(nums[i] > m){
10                return {false,-1};
11            }
12
13            if(sum + nums[i] > m){
14                kk++;
15                maxi = max(maxi, sum);
16                if(kk > k){
17                    return {false,-1};
18                }
19                
20                // if(kk == k && i == nums.size()-1 && ){
21                //     return true;
22                // }
23                // return false;
24                
25                sum = nums[i];
26            }else{
27                sum += nums[i];
28            }
29        }
30        maxi = max(sum,maxi);
31
32        return {true,maxi};
33    }
34    int splitArray(vector<int>& nums, int k) {
35        int low = 0;
36        int high = accumulate(nums.begin(),nums.end(), 0LL);
37        int ans = -1;
38        while(low <= high){
39            int m = low + (high - low) /2;
40            auto val = h(nums,k,m);
41            if(val.first){
42                ans = val.second;
43                high = m-1;
44            }else{
45                low = m+1;
46            }
47        }
48
49        return ans;
50    }
51};