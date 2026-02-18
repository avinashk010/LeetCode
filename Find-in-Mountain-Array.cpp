1/**
2 * // This is the MountainArray's API interface.
3 * // You should not implement it, or speculate about its implementation
4 * class MountainArray {
5 *   public:
6 *     int get(int index);
7 *     int length();
8 * };
9 */
10
11class Solution {
12public:
13    int findInMountainArray(int target, MountainArray &mountainArr) {
14        
15        int i = -1;
16
17        int len = mountainArr.length();
18
19        int ans = -1;
20
21        int l = 0;
22        
23        int r = len-1;
24
25        while(l<=r){
26            int m = l+(r-l)/2;
27
28            int val = mountainArr.get(m);
29            int b = -1;
30            int a = -1;
31            if(m-1 >= 0)
32                a = mountainArr.get(m-1);
33
34            if(m+1 <= len-1)
35                b = mountainArr.get(m+1);
36
37            if(a < val && val > b){
38                i = m;
39                break;
40            }else{
41                if(a < val && val < b){
42                    l = m+1;
43                }else{
44                    r = m-1;
45                }
46            }
47        }
48
49        /////peak found
50        // cout<<i;
51
52        l = 0;
53        r = i;
54
55        while(l<=r){
56            int m = l+(r-l)/2;
57            int val = mountainArr.get(m);
58
59            if(val >= target){
60                if(val == target)
61                    ans = m;
62                r = m-1;
63            }else{
64                l = m+1;
65            }
66        }
67
68        if(ans == -1){
69            l = i;
70            r = len-1;
71            while(l<=r){
72                int m = l+(r-l)/2;
73                int val = mountainArr.get(m);
74
75                if(val >= target){
76                    if(val == target)
77                        ans = m;
78                    l = m+1;
79                }else{
80                    r = m-1;
81                }
82            }
83        }
84
85        return ans;
86    }
87};