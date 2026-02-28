1class Solution {
2public:
3    vector<int> makeParityAlternating(vector<int>& nums) {
4        int one = 0;
5        int two =0;
6        for(int i=0; i<nums.size(); i++){
7            if((abs(nums[i])%2) == (i%2)){ //odd p odd, even p even
8                two++;
9            }else{
10                one++;
11            }
12        }
13        vector<int>cpy = nums;
14
15        vector<int>ans(2,0);
16
17        // cout<<one<<" "<<two;
18
19        int maxi = *max_element(nums.begin(),nums.end());
20        int mini = *min_element(nums.begin(),nums.end());
21        if(two < one){ //odd p even 
22            ans[0] = two;
23            int c = two;
24            for(int i=0; i<nums.size(); i++){
25                if((abs(nums[i])%2) == (i%2)){
26                    if(nums[i] == maxi){
27                        nums[i]--;
28                    }else{
29                        if(nums[i] == mini){
30                            nums[i]++;
31                        }else{
32                            // nums[i]--;
33                        }
34                    }
35                    c--;
36                    if(c==0)break;
37                }
38            }
39
40            int nmaxi = *max_element(nums.begin(),nums.end());
41            int nmini = *min_element(nums.begin(),nums.end());
42
43            ans[1] = nmaxi-nmini;
44            return ans;
45
46        }else if(one < two){ //odd p odd
47            ans[0] = one;
48            int c = one;
49            for(int i=0; i<nums.size(); i++){
50            if((abs(nums[i])%2) != (i%2)){
51                    // cout<<i<<" "<<maxi;
52                    if(nums[i] == maxi){
53                        nums[i]--;
54                    }else{
55                        if(nums[i] == mini){
56                            nums[i]++;
57                        }else{
58                            // nums[i]--;
59                        }
60                    }
61                    c--;
62                    if(c==0)break;
63                }
64            }
65            // for(int i=0; i<nums.size(); i++){
66            //     if((abs(nums[i])%2) != (i%2)){
67            //         if(nums[i] == maxi){
68            //             nums[i]--;
69            //             c--;
70            //         }
71            //         if(c == 0)break;
72            //     }
73            // }
74            
75            int nmaxi = *max_element(nums.begin(),nums.end());
76            
77            int nmini = *min_element(nums.begin(),nums.end());
78
79            ans[1] = nmaxi-nmini;
80            return ans;
81
82        }else{
83            ans[0] = one;
84
85            int c = one;
86            for(int i=0; i<nums.size(); i++){
87                if((abs(nums[i])%2) != (i%2)){
88                    if(nums[i] == maxi){
89                        nums[i]--;
90                    }else{
91                        if(nums[i] == mini){
92                            nums[i]++;
93                        }else{
94                            // nums[i]--;
95                        }
96                    }
97                    c--;
98                    if(c == 0)break;
99                }
100            }
101            int nmaxi = *max_element(nums.begin(),nums.end());
102            int nmini = *min_element(nums.begin(),nums.end());
103
104            int oneval = nmaxi-nmini;
105
106            
107            c = two;
108            nums = cpy;
109
110            for(int i=0; i<nums.size(); i++){
111                if((abs(nums[i])%2) == (i%2)){
112                    if(nums[i] == maxi){
113                        nums[i]--;
114                    }else{
115                        if(nums[i] == mini){
116                            nums[i]++;
117                        }else{
118                            // nums[i]--;
119                        }
120                    }
121                    c--;
122                    if(c==0)break;
123                }
124            }
125
126            nmaxi = *max_element(nums.begin(),nums.end());
127            nmini = *min_element(nums.begin(),nums.end());
128
129            int twoval = nmaxi-nmini;
130            ans[1] = min(oneval,twoval);
131
132            return ans;
133        }
134
135        return ans;
136        
137    }
138};