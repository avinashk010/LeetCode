1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
4        long long ans = 0;
5        for(int i =0; i<bl.size(); i++){
6            for(int j = i+1; j<tr.size(); j++){
7                if(bl[i][1] >= tr[j][1] || tr[i][1] <= bl[j][1]){
8                    continue;
9                }
10                if(bl[i][0] >= tr[j][0] || tr[i][0] <= bl[j][0]){
11                    continue;
12                }
13                pair<long long,long long> nbl = {max(bl[i][0], bl[j][0]), max(bl[i][1], bl[j][1])};
14                pair<long long,long long>ntr = {min(tr[i][0], tr[j][0]), min(tr[i][1], tr[j][1])};
15                
16                long long x = abs(nbl.first - ntr.first);
17                long long y = abs(nbl.second - ntr.second);
18                ans = max(ans, min(x,y));
19
20            }
21        }
22        return 1LL*ans*ans;
23    }
24};