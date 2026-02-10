1class Solution {
2public:
3    int minCostConnectPoints(vector<vector<int>>& points) {
4        vector<bool>done(points.size(), false);
5        int ans =0;
6        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
7        pq.push({0,0});
8
9        while(!pq.empty()){
10            auto tp = pq.top();
11            pq.pop();
12
13            if(done[tp.second]) continue;
14            done[tp.second] = true;
15            ans += tp.first;
16
17            for(int i =0; i<points.size(); i++){
18                if(!done[i]){
19                    int cost = abs(points[i][0] - points[tp.second][0]) + abs(points[i][1] - points[tp.second][1]);
20                    pq.push({cost,i});
21                }
22            }
23        }
24        return ans;
25    }
26};