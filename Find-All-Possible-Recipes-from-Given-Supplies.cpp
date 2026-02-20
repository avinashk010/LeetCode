1class Solution {
2public:
3    bool dfs(string now, unordered_map<string,vector<string>>&kkc, unordered_set<string>&vis,unordered_set<string>&bori,unordered_set<string>& recipeSet){
4        if(bori.count(now)) return true;
5        
6        if(vis.find(now) != vis.end()){
7            return false;
8        }
9
10        if(!recipeSet.count(now)) return false;
11
12        vis.insert(now);
13
14        for(auto &nbr : kkc[now]){
15            if(dfs(nbr, kkc, vis,bori,recipeSet) == false) return false;
16        }
17
18        vis.erase(vis.find(now));
19
20        bori.insert(now);
21
22        return true;
23    }
24    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingre, vector<string>& supplies) {
25        unordered_map<string,vector<string>>kkc;
26
27        unordered_set<string>bori(supplies.begin(),supplies.end());
28
29        unordered_set<string> recipeSet(recipes.begin(), recipes.end());
30      
31        unordered_set<string>finalbori(recipes.begin(),recipes.end());
32        for(int i=0; i<supplies.size(); i++){
33            finalbori.insert(supplies[i]);
34        }
35
36        unordered_set<string>np;
37     
38        for(int i=0; i<recipes.size(); i++){
39        
40            for(int j =0; j<ingre[i].size(); j++){
41                if(finalbori.find(ingre[i][j]) == finalbori.end()){
42                    np.insert(recipes[i]);
43                }
44                if(bori.find(ingre[i][j]) == bori.end()){ //bosi mai nhi h
45                 
46                    kkc[recipes[i]].push_back(ingre[i][j]);
47                }
48            }
49        }
50
51        vector<string>ans;
52
53        unordered_set<string>vis;
54
55        for(int i=0; i<recipes.size(); i++){
56
57            if(np.find(recipes[i]) != np.end()){
58                continue;
59            }
60            if(dfs(recipes[i], kkc, vis,bori,recipeSet) ){
61                ans.push_back(recipes[i]);
62            }
63          
64        }
65        return ans;
66    }
67};