1class Solution {
2public:
3    const int mod = 1e9+7;
4    int maxSumMinProduct(vector<int>& nums) {
5        int size = nums.size();
6        vector<int>n(size, size);
7        vector<int>p(size, -1);
8
9        stack<int>st;
10
11        for(int i=0; i<nums.size(); i++){
12            while(!st.empty() && nums[st.top()] >= nums[i]){
13                st.pop();
14            }
15            
16            if(!st.empty())
17                p[i] = st.top();
18
19            st.push(i);
20        }
21
22        
23        while(!st.empty()) st.pop();
24
25
26        for(int i=nums.size()-1; i>=0; i--){
27            while(!st.empty() && nums[st.top()] >= nums[i]){
28                st.pop();
29            }
30
31            if(!st.empty()){
32                n[i] = st.top();
33            }
34
35            st.push(i);
36        }
37
38        vector<long long>pre(size,0);
39        pre[0] = nums[0];
40        for(int i=1; i<size; i++){
41            pre[i] += pre[i-1] + nums[i];
42        }
43
44        long long ans =0;
45
46        for(int i=0; i<size; i++){
47            int pi = p[i];
48            int ni = n[i];
49
50            
51
52            long long sum = pre[ni-1];
53
54            if(pi != -1){
55                sum -= pre[pi];
56            }
57
58            ans = max(ans, 1LL * sum * nums[i]);
59
60        
61        }
62
63        
64
65        return ans%mod;
66    }
67};