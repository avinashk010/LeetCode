1class Solution {
2public:
3    int minPartitions(string& n) {
4        int maxi = 0;
5        for(int i=0; i<n.length(); i++){
6            if(n[i] - '0' > maxi){
7                maxi = n[i] - '0';
8            }
9            if(maxi == 9) break;
10        }
11        return maxi;
12    }
13};