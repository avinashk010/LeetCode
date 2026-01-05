1class Solution {
2public:
3    int minimumOperations(vector<int>& nums) {
4        if(nums.size() ==1){
5            return 0;
6        }
7        unordered_map<int,int>ev;
8        unordered_map<int,int>odd;
9
10        int od_max = -1;
11        int q = -1;
12
13        int ev_max = -1;
14        int e_q = -1;
15
16        for(int i=0; i<nums.size(); i++){
17            if(i&1){
18                odd[nums[i]]++;
19                if(odd[nums[i]] > q){
20                    od_max = nums[i];
21                    q = odd[nums[i]];
22                }
23            }else{
24                ev[nums[i]]++;
25                if(ev[nums[i]] > e_q){
26                    ev_max = nums[i];
27                    e_q = ev[nums[i]];
28                }
29            }
30        }
31            int one = -1;
32            int two = -1;
33        if(od_max != ev_max){
34            return nums.size() - e_q - q;
35        }else{
36            // if(q>=e_q){ // odd wala jada h
37                ev[ev_max] = -1;
38                int quan = 0;
39                int val = -1;
40                for(auto& ele : ev){
41                    if(ele.second > quan){
42                        quan = ele.second;
43                        val = ele.first;
44                    }
45                }
46                one = nums.size() - q - quan;
47            // }else{
48                // cout<<"HI";
49                odd[od_max] = -1;
50                quan = 0;
51                 val = -1;
52                 for(auto & ele : odd){
53                    if(ele.second > quan){
54                        quan = ele.second;
55                         val = ele.first;
56                    }
57                 }
58                //  cout<<e_q<<" "<<quan;
59                 two = nums.size() - e_q - quan;
60            // }
61        }
62        return min(one,two);
63
64    }
65};