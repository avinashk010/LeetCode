1class Solution {
2public:
3    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
4        int jump = 1;
5        vector<vector<int>>ans;
6        bool ld = true;
7        ans.push_back({rStart,cStart});
8        int r = rStart;
9        int c = cStart;
10        while(ans.size() < (rows*cols)){
11            if(ld){
12                for(int i=0; i<jump; i++){
13                    c++;
14                    if(c<cols && c>=0 && r<rows && r>=0){
15                        ans.push_back({r,c});
16                    }
17                }
18                for(int i =0; i<jump; i++){
19                    r++;
20                    if(r<rows && r>=0 && c<cols && c>=0){
21                        ans.push_back({r,c});
22                    }
23                }
24                ld = false;
25                jump++;
26            }else{
27                for(int i =0; i<jump; i++){
28                    c--;
29                    if(c<cols && c>=0 && r<rows && r>=0){
30                        ans.push_back({r,c});
31                    }
32                }
33                for(int i=0; i<jump; i++){
34                    r--;
35                    if(r<rows && r>=0 && c<cols && c>=0){
36                        ans.push_back({r,c});
37                    }
38                }
39                ld = true;
40                jump++;
41            }
42        }
43        return ans;
44    }
45};