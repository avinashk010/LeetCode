1class Solution {
2public:
3    bool check(vector<vector<int>>& squares, double mid_y, double total) {
4        double bot_area = 0;
5
6        for(auto &square : squares) {
7            double y = square[1];
8            double l = square[2];
9
10            double boty = y;
11            double topy = y + l;
12
13            if (mid_y >= topy) {
14                //full square below
15                bot_area += l * l;
16            } else if (mid_y > boty) {
17                //partial area below
18                bot_area += (mid_y - boty) * l;
19            }
20        }
21
22        return bot_area >= total/2.0; //Is bottom area more than above ?
23    }
24
25    double separateSquares(vector<vector<int>>& squares) {
26        double low   = INT_MAX;
27        double high  = INT_MIN;
28        double total = 0.00000;
29
30        for(auto &square : squares) {
31            double x = square[0];
32            double y = square[1];
33            double l = square[2];
34            total   += l*l;
35
36            low  = min(low, y);
37            high = max(high, y+l);
38        }
39
40        double result_y = 0.00000;
41
42        while(high-low > 1e-5) {
43            double mid_y = low + (high-low)/2;
44            
45            result_y = mid_y;
46
47            if (check(squares, mid_y, total) == true) { //bottom area is greater
48                //shift mid_y down side to balance area
49                high = mid_y;
50            } else {
51                low = mid_y;
52            }
53        }
54
55
56        return result_y;
57    }
58};