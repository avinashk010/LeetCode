1class Solution {
2public:
3    int maxScoreSightseeingPair(vector<int>& values) {
4        int now = values[0];
5        int ans =0;
6        for(int i =1; i<values.size(); i++){
7            ans = max(ans, -i+now+values[i]);
8            now = max(now, values[i] + i);
9        }
10        return ans;
11    }
12};