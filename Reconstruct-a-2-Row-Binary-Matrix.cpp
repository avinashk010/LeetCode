1class Solution {
2public:
3    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
4        vector<vector<int>>v(2,vector<int>(colsum.size(),0));
5        for(int i =0; i<colsum.size(); i++){
6            if(colsum[i] == 2){
7                v[0][i] = 1;
8                v[1][i] = 1;
9                upper--;
10                lower--;
11                if(upper < 0 || lower < 0){
12                    v.clear();
13                    return v;
14                }
15            }
16        }
17        for(int i=0; i<colsum.size(); i++){ 
18            if(colsum[i] == 1){
19                if(upper){
20                    v[0][i] = 1;
21                    upper--;
22                }else if(lower){
23                    v[1][i] = 1;
24                    lower--;
25                }else{
26                    v.clear();
27                    return v;
28                }
29            }
30        }
31        if(lower > 0 || upper > 0){
32            v.clear();
33            return v;
34        }
35        return v;
36    }
37};