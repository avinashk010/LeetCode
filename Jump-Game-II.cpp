1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        if(nums.size()==1) return 0;
5        int li = nums.size()-1;
6        int i=0;
7        int ans=1;
8        while(i<nums.size()){
9            if (i + nums[i] >= li) return ans; 
10            int maxi=-1;
11            int ii=-1;
12            for(int j=i+1; j<=i+nums[i]; j++){
13                // if(j>=li) return ans;
14                if(maxi < nums[j]+j){
15                    maxi = nums[j] +j;
16                    ii = j;
17                    
18                }
19            }
20            // if (ii == -1) return false;
21            // cout<<ii<<endl;
22            i=ii;
23            // if(nums[i] == 0 && i<li) return ans;
24            ans++;
25        }
26        return ans;
27    }
28};