class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        if (rounds.back() < rounds[0]){
            for (int i=1; i<=rounds.back(); i++){
                res.push_back(i);
            }
            for (int i=rounds[0]; i<=n; i++){
                res.push_back(i);
            }
        }else{
            for (int i=rounds[0]; i<=rounds.back(); i++){
                res.push_back(i);
            }
        }
        return res;
    }
};