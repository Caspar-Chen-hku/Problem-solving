class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> occur;
        int count = 0;
        int i=0, j=0;
        for (char c:t){
            occur[c]++;
        }
        count = occur.size();
        string res; int len = INT_MAX;
        while (j < s.length()){
            while (j < s.length() && count>0){
                if (occur.count(s[j])>0){
                    occur[s[j]]--;
                    if (occur[s[j]]==0) count--;
                }
                j++;
            }
            if (count == 0){
                string cur = s.substr(i, j-i);
                if (cur.length()<len){
                    len = cur.length();
                    res = cur;
                }
            }
            while (i < j && count<t.length()){
                if (occur.count(s[i])>0){
                    occur[s[i]]++;
                    if (occur[s[i]]==1) count++;
                }
                i++;
                if (count==0){
                    string cur = s.substr(i, j-i);
                    if (cur.length()<len){
                        len = cur.length();
                        res = cur;
                    }
                }
            }
        }
        return res;
    }
};