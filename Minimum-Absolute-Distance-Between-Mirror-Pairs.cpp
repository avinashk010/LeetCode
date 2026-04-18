1class Solution {
2public:
3    int minMirrorPairDistance(vector<int>& nums) {
4        unordered_map<int,int>mp;
5
6        int ans = INT_MAX;
7
8        for(int i=nums.size()-1; i>=0; i--){
9            int val = 0;
10
11            int num = nums[i];
12
13            while(num){
14                val*=10;
15                val+=num%10;
16                num/=10;
17            }
18
19            // cout<<val<<endl;
20
21            if(mp.find(val) != mp.end()){
22                ans = min(ans, abs(i - mp[val]));
23            }  
24            num = nums[i];
25            // while(num%10 == 0){
26            //     num/=10;
27            // }
28
29            
30
31            mp[num] = i;
32        }
33
34        if(ans == INT_MAX) return -1;
35        return ans;
36    }
37};