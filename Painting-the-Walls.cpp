1class Solution {
2public:
3    vector<vector<long long>>dp;
4    long long h(int i,int left, vector<int>&cost, vector<int>&time){
5        if(left<=0){
6            return 0;
7        }
8        if(i>=cost.size()){
9            return INT_MAX;
10        }
11        if(dp[i][left] != -1) return dp[i][left];
12
13        //take
14        long long one = cost[i] + h(i+1, left-time[i]-1, cost,time);
15        
16        long long two = h(i+1, left,cost,time);
17
18        return dp[i][left] = min(one,two);
19    }
20    int paintWalls(vector<int>& cost, vector<int>& time) {
21        dp.assign(cost.size()+1,vector<long long>(cost.size()+1,-1));
22        return h(0,cost.size(),cost,time);
23    }
24};