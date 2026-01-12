1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int ans =0;
5        for(int i =1; i<points.size(); i++){
6            int x = abs(points[i][0] - points[i-1][0]);
7            int y = abs(points[i][1] - points[i-1][1]);
8
9            ans += max(x,y);
10            
11        }
12        return ans;
13    }
14};