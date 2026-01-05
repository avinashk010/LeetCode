1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4        long long sum =0;
5        int smallest = INT_MAX;
6        int neg=0;
7        for(int i=0; i<matrix.size(); i++){
8            for(int j=0; j<matrix[0].size(); j++){
9                if(matrix[i][j] < 0) neg++;
10                sum +=  abs(matrix[i][j]);
11                smallest = min(smallest, abs(matrix[i][j]));
12            }
13        }
14        if(neg&1) sum -= 2*smallest;
15        return sum;
16        
17    }
18};