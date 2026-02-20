1class Solution {
2public:
3    string kthLargestNumber(vector<string>& nums, int k) {
4        vector<int>q(101,0);
5
6        for(int i=0; i<nums.size(); i++){
7            q[nums[i].size()]++;
8        }
9        int size = -1;
10
11        int hatao = k;
12    
13        for(int i=q.size()-1; i>=0; i--){
14            hatao = k;
15            k-=q[i];
16            if(k<=0){
17                size = i;
18                break;
19            }
20        }
21
22        vector<string>v;
23
24        for(int i =0; i<nums.size(); i++){
25            if(nums[i].size() == size){
26                v.push_back(nums[i]);
27            }
28        }
29        
30        sort(v.begin(),v.end());
31
32        // cout<<size<<endl;
33        // cout<<hatao;
34
35        for(int i=v.size()-1; i>=0; i--){
36            hatao--;
37            if(hatao == 0){
38                return v[i];
39            }
40        }
41
42        return "";
43
44
45
46        
47        
48    }
49};