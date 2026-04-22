1class Solution {
2public:
3    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
4        int n = profits.size();
5
6        vector<pair<int,int>> both;
7        for(int i = 0; i < n; i++){
8            both.push_back({capital[i], profits[i]});
9        }
10
11        sort(both.begin(), both.end());
12        //tc nlogn sc n
13
14        priority_queue<int>pq;
15
16        int it = 0;
17
18        
19    
20        for(int i=0; i<k; i++){
21            while(it < both.size() && w >= both[it].first){
22                pq.push((both[it]).second);
23                it++;
24            }
25
26            if(pq.empty()) break;
27            w+=pq.top();
28            pq.pop();
29        }
30
31        //tc max((k + n)logn) sc n
32
33        return w;
34    }
35};