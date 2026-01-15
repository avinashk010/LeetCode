1class Solution {
2public:
3    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
4        sort(hBars.begin(),hBars.end());
5        sort(vBars.begin(),vBars.end());
6
7        int count = 1;
8        int a;
9        if(hBars.size()>0){
10            a = 1;
11        }else{
12            a = 0;
13        }
14        for(int i=1; i<hBars.size(); i++){
15            if(hBars[i] - 1 == hBars[i-1]){
16                count++;
17                a = max(a,count);
18            }else{
19                count = 1;
20                
21            }
22        }
23        count = 1;
24        int b;
25        if(vBars.size()>0) b = 1;
26        else b = 0;
27        for(int i=1; i<vBars.size(); i++){
28            if(vBars[i] - 1 == vBars[i-1]){
29                count++;
30                b = max(b,count);
31            }else{
32                count = 1;
33                
34            }
35        }
36        // cout<<a<<b;
37        int val = min(a,b);
38        // cout<<val;
39
40        return (val+1) * (val+1);
41
42    }
43};