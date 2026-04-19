1class Solution {
2public:
3    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0, j = 0, ans = 0;
5
6        while (i < nums1.size() && j < nums2.size()) {
7            if (nums1[i] <= nums2[j]) {
8                ans = max(ans, j - i);
9                j++;
10            } else {
11                i++;
12            }
13        }
14        return ans;
15    }
16};