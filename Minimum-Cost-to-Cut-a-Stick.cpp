1class Solution {
2public:
3    // unordered_map<int,unordered_map<int,int>>dp;
4    // int h(int i,int j,vector<int>&cuts){
5
6    //     bool hua= false;
7        
8    //     int ans = INT_MAX;
9
10    //     if(dp.find(i) != dp.end()){
11    //         if(dp[i].find(j) != dp[i].end()){
12    //             return dp[i][j];
13    //         }
14    //     }
15    //     for(int c = 0; c<cuts.size(); c++){
16    //         if(cuts[c] > j) break;
17    //         if(cuts[c] > i && cuts[c] < j){
18    //             hua = true;
19    //             int val = j-i;
20    //             int one = h(i,cuts[c], cuts);
21    //             int two = h(cuts[c],j, cuts);
22
23    //             ans = min(ans, val+one+two);
24    //         }
25    //     }
26    //     if(!hua){
27    //         return dp[i][j] = 0;
28    //     }
29    //     return dp[i][j] = ans;
30    // }
31    int minCost(int n, vector<int>& cuts) {
32        cuts.push_back(0);
33        cuts.push_back(n);
34
35        sort(cuts.begin(),cuts.end());
36        
37        long long m = cuts.size();
38
39        vector<vector<long long>>dp(m+1,vector<long long>(m+1, INT_MAX));
40
41
42        for(int i =0; i+1<m; i++){
43            dp[i][i+1] = 0;
44        }
45
46        for(long long len = 2; len < m; len++){
47            for(long long l=0; l+len<m; l++){
48                long long r = l + len;
49                // if(r-l == 1){
50                //     dp[l][r] = 0;
51                //     continue;
52                // }
53
54                bool hua = false;
55                long long take = INT_MAX;
56                for(long long c = l+1; c<r; c++){
57                    hua = true;
58                    long long val = cuts[r] - cuts[l];
59                    long long one = dp[l][c];
60                    long long two = dp[c][r];
61
62                    take= min(take, val+one+two);
63                }
64                if(!hua) break;
65                if(take >= INT_MAX) continue;
66                dp[l][r] = take;
67            }
68        }
69
70        return dp[0][m-1];
71
72        // return h(0,n,cuts);
73    }
74};