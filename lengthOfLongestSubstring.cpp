class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> occur;
        if (s.empty()) return 0;
        int i = 0, j = 0, curmax = 1;
        occur[s[0]] = 1;
        while (j+1 < s.length()){
            j++;
            occur[s[j]]++;
            if (occur[s[j]]>1){
                curmax = max(curmax, j-i);
                while (s[i]!=s[j]){
                    occur[s[i]]--;
                    i++;
                }
                occur[s[i]]--;
                i++;
            }
        }
        return max(curmax, j+1-i);
    }
};