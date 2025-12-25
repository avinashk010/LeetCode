1class Solution {
2public:
3    long long maximumHappinessSum(vector<int>& h, int k) {
4        long long ans =0;
5        sort(h.rbegin(),h.rend());
6    
7        int neg = 0;
8        for(int i=0; i<min((int)h.size(),k) ; i++){
9            h[i]+=neg;
10            neg--;
11            if(h[i] <= 0) break;
12            ans += h[i];
13        }
14        return ans;
15    }
16};