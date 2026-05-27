1class Solution {
2public:
3    int digits(int x) {
4        int cnt = 0;
5        while(x > 0) {
6            cnt++;
7            x /= 10;
8        }
9        return cnt;
10    }
11
12    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
13        unordered_set<int> st;
14
15        for(int num : arr1) {
16            int x = num;
17            while(x > 0) {
18                st.insert(x);
19                x /= 10;
20            }
21        }
22
23        int ans = 0;
24
25        for(int num : arr2) {
26            int x = num;
27            int len = digits(num);
28
29            while(x > 0) {
30                if(st.count(x)) {
31                    ans = max(ans, len);
32                    break;
33                }
34                x /= 10;
35                len--;
36            }
37        }
38
39        return ans;
40    }
41};