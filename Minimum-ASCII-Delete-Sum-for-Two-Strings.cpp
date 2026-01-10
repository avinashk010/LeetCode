1class Solution {
2public:
3    vector<vector<int>>dp;
4    int h(int i, int j, string& a, string& b){
5
6        if( i >= a.length() || j >= b.length()){
7            int val = 0;
8            if(i>=a.length()){
9                while(j <b.length()){
10                    val += b[j];
11                    j++;
12                }
13            }else{
14                while(i<a.length()){
15                    val += a[i];
16                    i++;
17                }
18            }
19            return val;
20        }
21
22        if(dp[i][j] != -1) return dp[i][j];
23    
24
25        int ans = INT_MAX;
26        if(a[i] == b[j]){
27            int one = h(i+1, j+1, a, b);
28            ans = min(ans, one);
29        }else{
30            int two = a[i] + h(i+1, j, a,b);
31            int three = b[j] + h(i, j+1, a, b);
32            ans = min({ans,two, three});
33        }
34        return dp[i][j] = ans;
35    }
36    int minimumDeleteSum(string& s1, string& s2) {
37        dp.assign(s1.length(), vector<int>(s2.length(),-1));
38        return h(0,0,s1,s2);
39    }
40};