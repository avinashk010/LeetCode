1class Solution {
2public:
3    int bestClosingTime(string& c) {
4        int ans = -1;
5        int mini = INT_MAX;
6        int noo = 0;
7        int tot = 0;
8
9    
10        
11        for(int i=0; i<c.length(); i++){
12            if(c[i] == 'Y'){
13                tot++;
14            }
15        }
16
17        // if(tot == c.length()) return c.length();
18
19        c.push_back('N');
20
21        for(int i=0; i<c.length(); i++){
22            int piche_yes = i-noo;
23            int aage_yes = tot-piche_yes;
24
25            int temp_p = noo+aage_yes;
26
27            if(temp_p<mini){
28                mini = temp_p;
29                ans = i;
30            }
31
32            if(c[i] == 'N'){
33                noo++;
34            }
35
36        }
37        return ans;
38    }
39};