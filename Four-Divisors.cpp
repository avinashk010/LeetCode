1class Solution {
2public:
3    int sumFourDivisors(vector<int>& nums) {
4        unordered_map<int,vector<int>>mp;
5        int maxi = *max_element(nums.begin(),nums.end());
6
7        for(int i=1; i<=maxi; i++){
8            for(int j = i; j<=maxi; j+=i){
9                mp[j].push_back(i);
10            }
11        }
12
13        int sum = 0;
14        // auto vec = mp[21];
15        // for(int i=0; i<vec.size(); i++){
16        //     cout<<vec[i]<<" ";
17        // }
18        for(int i=0; i<nums.size(); i++){
19            if(mp[nums[i]].size() == 4){
20                sum += accumulate(mp[nums[i]].begin(),mp[nums[i]].end(), 0);
21            }
22        }
23        return sum;
24    }
25};