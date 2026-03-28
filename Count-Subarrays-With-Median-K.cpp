1class Solution {
2public:
3    int countSubarrays(vector<int>& nums, int k) {
4        vector<int>v(nums.size(), 0);
5
6        int ind = -1;
7        int ans = 1;
8        for(int i=0; i<nums.size(); i++){
9            if(nums[i] == k){
10                ind = i;
11                break;
12            }
13        }
14        int i = ind;
15        while(--i>=0){
16            if(nums[i] > k){
17                v[i] = v[i+1]+1;
18            }else{
19                v[i] = v[i+1]-1;
20            }
21            if(v[i] == 0 || v[i] == 1){
22                ans++;
23            }
24    
25        }
26        i = ind;
27        while(++i<nums.size()){
28            if(nums[i] > k){
29                v[i] = v[i-1]+1;
30            }else{
31                v[i] = v[i-1]-1;
32            }
33            if(v[i] == 0 || v[i] == 1){
34                ans++;
35            }
36        }
37
38        unordered_map<int,int>left;
39
40        for(int i=0; i<ind; i++){
41            left[v[i]]++;
42        }
43
44        for(int i = ind+1; i<nums.size(); i++){
45            int val = v[i];
46            ans += left[-val];
47            ans += left[-(val-1)];
48          
49        }
50
51        return ans;
52        
53    }
54};