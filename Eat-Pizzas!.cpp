1class Solution {
2public:
3    long long maxWeight(vector<int>& pizzas) {
4        int s = pizzas.size()/4;
5        sort(pizzas.begin(),pizzas.end());
6        long long ans = 0;
7        if(s&1){
8            int last = (s+1)/2;
9            int i = pizzas.size()-1;
10            while(last--){
11                ans+=pizzas[i];
12                i--;
13            }
14            last = s/2;
15            i--;
16            while(last--){
17                ans += pizzas[i];
18                i-=2;
19            }
20            return ans;
21        }else{
22            int last = (s)/2;
23            int i = pizzas.size()-1;
24            while(last--){
25                ans+=pizzas[i];
26                i--;
27            }
28            last = s/2;
29            i--;
30            while(last--){
31                ans += pizzas[i];
32                i-=2;
33            }
34            return ans;
35        }
36        return ans;
37    }
38};