1class Solution {
2public:
3    map<int,map<int,int>>dp;
4    int h(int i,int j,vector<int>&cuts){
5        
6        bool hua= false;
7        
8        int ans = INT_MAX;
9
10        if(dp.find(i) != dp.end()){
11            if(dp[i].find(j) != dp[i].end()){
12                return dp[i][j];
13            }
14        }
15        for(int c = 0; c<cuts.size(); c++){
16            if(cuts[c] > i && cuts[c] < j){
17                hua = true;
18                int val = j-i;
19                int one = h(i,cuts[c], cuts);
20                int two = h(cuts[c],j, cuts);
21
22                ans = min(ans, val+one+two);
23            }
24        }
25        if(!hua){
26            return 0;
27        }
28        return dp[i][j] = ans;
29    }
30    int minCost(int n, vector<int>& cuts) {
31        
32        return h(0,n,cuts);
33    }
34};