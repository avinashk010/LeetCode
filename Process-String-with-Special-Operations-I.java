1class Solution {
2    public String processStr(String s) {
3        StringBuilder res = new StringBuilder();
4
5        for(int i =0; i<s.length(); i++){
6            char ch = s.charAt(i);
7            if(ch >= 'a' && ch <= 'z'){
8                res.append(ch);
9            }else if(ch == '*'){
10                if(res.length()>0) res.deleteCharAt(res.length() - 1);
11            }else if(ch == '#'){
12                res.append(res);   
13            }else{
14                res.reverse();
15            }
16        }
17
18        return res.toString();
19    }
20}