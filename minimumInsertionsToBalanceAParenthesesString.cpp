class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) ans++;
                if(i+1>=s.length()) ans++;
                if(i+1<s.length() && s[i+1] == '(') ans++;
                else if(i+1<s.length() && s[i+1] == ')') i++;
                if(!st.empty())
                st.pop();
            }
        }
        return ans += st.size()*2;
    }
};