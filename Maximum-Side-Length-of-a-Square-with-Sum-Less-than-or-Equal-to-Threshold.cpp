1class Solution {
2public:
3    
4    int maxSideLength(vector<vector<int>>& mat, int threshold) {
5
6        vector<vector<int>>pre(mat.size(), vector<int>(mat[0].size(), 0));
7
8        for(int i=0 ;i<mat.size(); i++){
9            for(int j=0; j<mat[0].size(); j++){
10                pre[i][j] = mat[i][j];
11                if(j) pre[i][j] += pre[i][j-1];
12            }
13        }
14
15        int len = 0;
16
17        for (int i = 0; i < mat.size(); i++) {
18            for (int j = 0; j < mat[0].size(); j++) {
19                int right = mat[0].size() - j;
20                int down = mat.size() - i;
21                int check = len + 1;
22                for(int x = check; x <= min(right,down); x++){
23                    int sum = 0;
24                    for(int d = i; d<i+x; d++){
25                        sum += pre[d][j+x-1];
26                        if(j) sum -= pre[d][j-1];
27                    }
28                    if(sum <= threshold){
29                        len = max(len,x);
30                    }else break;
31                }
32            }
33        }
34        return len;
35    }
36};