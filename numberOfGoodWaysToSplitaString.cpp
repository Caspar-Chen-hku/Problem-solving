class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> precount(n);
        vector<int> postcount(n);
        set<char> letters;
        for (int i=0; i<n; i++){
            letters.insert(s[i]);
            precount[i] = letters.size();
        }
        letters.clear();
        for (int i=n-1; i>=0; i--){
            letters.insert(s[i]);
            postcount[i] = letters.size();
        }
        int res = 0;
        for (int i=0; i<n-1; i++){
            if (precount[i] == postcount[i+1]){
                res++;
            }
        }
        return res;
    }
};