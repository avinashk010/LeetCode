1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        vector<vector<int>>left0(m,vector<int>(n,-1));
8        for(int i=0; i<m; i++){
9            int zeroi=-1;
10            for(int j=0; j<n;j++){
11                if(matrix[i][j] == '0'){
12                    zeroi = j;
13                    continue;
14                }
15                left0[i][j] = j-zeroi;
16            }
17        }
18
19        int maxarea = -1;
20        for(int i=0; i<m; i++){
21            for(int j=0; j<n; j++){
22                if(matrix[i][j] == '0') continue;
23                int t = i;
24                int base = left0[i][j];
25                int h = 1;
26                while(t>=0 && left0[t][j] != -1){
27                    base = min(base,left0[t][j]);
28                    maxarea = max(maxarea,base*h);
29                    h++;
30                    t--;
31                }
32
33            }
34        }
35        if(maxarea == -1) return 0;
36        return maxarea;
37    }
38};