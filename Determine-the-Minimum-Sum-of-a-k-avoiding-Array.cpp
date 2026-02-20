1class Solution {
2public:
3    int minimumSum(int n, int k) {
4        int sum =0;
5        int c = 0;
6
7        int num = 1;
8        while(c<n && num<=(k/2)){
9            sum += num;
10            num++;
11            c++;
12        }
13
14        // cout<<sum;
15
16        num = k;
17      
18        while(c<n){
19            sum += num;
20            num++;
21            c++;
22        }
23
24        return sum;
25
26    }
27};