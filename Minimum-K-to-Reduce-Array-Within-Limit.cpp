1class Solution {
2public:
3    int minimumK(vector<int>& nums) {
4        long long l = 1;
5        long long r = 1e5;
6        long long ans = -1;
7
8        while(l<=r){
9            long long m = l + (r-l)/2;
10
11            long long c =0;
12            for(long long i=0; i<nums.size(); i++){
13                c += ceil((double)nums[i]/m);
14            }
15            if(c <= (m*m)){
16                ans = m;
17                r = m-1;
18            }else{
19                l = m+1;
20            }
21        }
22
23        return ans;
24    }
25};