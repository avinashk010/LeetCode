1class Solution {
2public:
3    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
4        multiset<pair<int,int>>st;
5
6        for(int i=0; i<profits.size(); i++){
7            st.insert({capital[i],profits[i]});
8        }
9
10        priority_queue<int>pq;
11
12        set<pair<int,int>>::iterator it = st.begin();
13
14        
15    
16        for(int i=0; i<k; i++){
17            while(it != st.end() && w >= (*it).first){
18                pq.push((*it).second);
19                it++;
20            }
21
22            if(pq.empty()) break;
23            w+=pq.top();
24            pq.pop();
25        }
26
27        return w;
28    }
29};