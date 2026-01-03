1class Solution {
2public:
3    int minLength(vector<int>& nums, int k) {
4        unordered_map<int,int> mp;
5        
6        int i = 0, sum = 0, ans = INT_MAX;
7        //MAPPP
8        for (int j = 0; j < nums.size(); j++) {
9            if (++mp[nums[j]] == 1) {
10                sum += nums[j];
11            }
12
13            while (sum >= k) {
14                ans = min(ans, j - i + 1);
15                if (--mp[nums[i]] == 0) {
16                    sum -= nums[i];
17                }
18                i++;
19            }
20        }
21
22        return ans == INT_MAX ? -1 : ans;
23    }
24};