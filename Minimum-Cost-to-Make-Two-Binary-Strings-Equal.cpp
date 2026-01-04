1class Solution {
2public:
3    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
4        long long w0 = 0;
5        long long w1 = 0;
6
7        for(long long i=0; i<t.length(); i++){
8            if(s[i] != t[i]){
9                if(s[i] == '0'){
10                    w0++;
11                }else{
12                    w1++;
13                }
14            }
15        }
16
17        long long ans = 0;
18
19        long long first_flip = flipCost * 2 * min(w0,w1);
20        long long first_swap = swapCost * min(w0,w1);
21        long long left = abs(w0-w1);
22
23        ans += min(first_flip,first_swap);
24
25        //left;
26        // cout<<ans;
27        
28        //agr all flip;
29
30        long long second_flip = flipCost * left;
31
32        //half cross then swap
33        //if odd then flip one
34        long long val = 0;
35        if(left&1){ val += flipCost; left--;}
36        
37        long long half_cross = crossCost * left/2;
38        val+= half_cross;
39
40        long long second_switch = swapCost * left/2;
41
42        val += second_switch;
43
44        ans += min(val, second_flip);
45
46        return ans;
47
48    }
49};