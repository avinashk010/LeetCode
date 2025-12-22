1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4    
5        vector<int>dp(strs.front().length(),1);
6       
7
8        for(int i=1; i<strs[0].length();i++){
9            for(int j = i-1; j>=0; j--){
10                bool ok = true;
11                for(int x = 0; x<strs.size(); x++){
12                    if(strs[x][j] > strs[x][i]){
13                        ok = false;
14                        break;
15                    }
16                }
17                if(ok){
18                    dp[i] = max(dp[i], 1 + dp[j]);
19                }
20            }
21        }
22        int maxi = -1;
23
24        for(int i=0; i<strs.front().size(); i++){
25            maxi = max(dp[i],maxi);
26        }
27        return strs.front().size() - maxi;
28    }
29};