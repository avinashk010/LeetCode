1class BrowserHistory {
2public:
3    int i = 0;
4    vector<string>pages;
5    BrowserHistory(string homepage) {
6        pages.clear();
7        pages.push_back(homepage);
8    }
9    
10    void visit(string url) {
11        pages.erase(pages.begin()+i+1,pages.end());
12        pages.push_back(url);
13        i = pages.size()-1;
14        return;
15    }
16    
17    string back(int steps) {
18        if(i-steps < 0){
19            i = 0;
20            return pages[0];
21        }
22        i = i-steps;
23        return pages[i];
24    }
25    
26    string forward(int steps) {
27        if(i+steps > pages.size()-1){
28            i = pages.size()-1;
29            return pages.back();
30        }
31        i = i+steps;
32        return pages[i];
33    }
34};
35
36/**
37 * Your BrowserHistory object will be instantiated and called as such:
38 * BrowserHistory* obj = new BrowserHistory(homepage);
39 * obj->visit(url);
40 * string param_2 = obj->back(steps);
41 * string param_3 = obj->forward(steps);
42 */