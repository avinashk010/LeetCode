1class Solution {
2public:
3    bool possible(int h, vector<int>&piles, int time){
4
5        long long c =0;
6        for(int i=0; i<piles.size(); i++){
7            c += ceil((long double)piles[i]/h);
8            if(c > time){
9                return false;
10            }
11        }
12
13        return true;
14    
15    }
16    int minEatingSpeed(vector<int>& piles, int h) {
17        
18        int l = 1;
19        int hi = *max_element(piles.begin(),piles.end());
20        int ans = h;
21
22        while(l<=hi){
23            int m = l + (hi-l)/2;
24
25            if(possible(m, piles,h)){
26                hi = m-1;
27                ans = m;
28            }else{
29                l = m+1;
30            }
31        }
32        return ans;
33    }
34};