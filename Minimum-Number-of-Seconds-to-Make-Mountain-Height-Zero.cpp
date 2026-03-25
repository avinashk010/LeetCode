1class Solution {
2public:
3    long long cal(long long n, int a) { return 1LL * a * n * (n + 1) / 2; }
4    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
5        long long l = *min_element(workerTimes.begin(), workerTimes.end());
6        long long mini = *min_element(workerTimes.begin(), workerTimes.end());
7
8        long long r = cal(mountainHeight, mini);
9        // int size = workerTimes.size();
10
11        // int left = mountainHeight - size;
12        // for(int i=0; i<workerTimes.size(); i++){
13        //     r += workerTimes[i];
14        // }
15        // r += cal(left, mini);
16        // r -= mini;
17
18        // cout << l << " " << r;
19        long long ans = 0;
20
21        auto possi = [&](long long m) {
22            long long sum = 0;
23            long long mul = 1;
24            long long remaining = mountainHeight;
25            for (long long i = 0; i < workerTimes.size(); i++) {
26                mul = 1;
27                sum = 0;
28                while (sum+(workerTimes[i]*mul) <= m) {
29                    sum += (workerTimes[i] * mul);
30                    remaining--;
31                    mul++;
32                    if (remaining <= 0)
33                        return true;
34                }
35            }
36            if (remaining <= 0)
37                return true;
38            return false;
39        };
40
41        while (l <= r) {
42            long long m = l + (r - l) / 2;
43            if (possi(m)) {
44                ans = m;
45                r = m - 1;
46            } else {
47                l = m + 1;
48            }
49        }
50
51        return ans;
52    }
53};