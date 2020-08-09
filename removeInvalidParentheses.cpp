class Solution {
public:
    
    bool isValid(string s){
        int l = 0;
        for (char c:s){
            if (c=='('){
                l++;
            }else if (c==')'){
                if (l>0) l--;
                else return false;
            }   
        }
        return l==0;
    }
    
    void dfs(string s, int start, int l, int r, vector<string>& res){
        if (l==0 && r==0){
            if (isValid(s)) res.push_back(s);
        }else{
            string curr;
            for (int i=start; i<s.length(); i++){
                if (i>start && s[i]==s[i-1]) continue;
                else if (s[i]==')' && r>0){
                    curr=s;
                    curr.erase(i, 1);
                    dfs(curr, i, l, r-1, res);
                }else if (s[i]=='(' && l>0){
                    curr=s;
                    curr.erase(i, 1);
                    dfs(curr, i, l-1, r, res);
                }
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int l=0, r=0;
        for (char c:s){
            if (c=='('){
                l++;
            }else if (c==')'){
                if (l>0) l--;
                else r++;
            }
        }
        vector<string> res;
        dfs(s, 0, l, r, res);
        return res;
    }
};