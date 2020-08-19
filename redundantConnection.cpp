class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, int> color;
        int cur = 0;
        for (auto e:edges){
            if (color.count(e[0])>0 && color.count(e[1])>0){
                if (color[e[0]] == color[e[1]]){
                    return e;
                }else{
                    int target = min(color[e[0]], color[e[1]]);
                    int change = max(color[e[0]], color[e[1]]);
                    for (auto& p:color){
                        if (p.second == change){
                            p.second = target;
                        }
                    }
                }
            }else if (color.count(e[0]) > 0){
                color[e[1]] = color[e[0]];
            }else if (color.count(e[1]) > 0){
                color[e[0]] = color[e[1]];
            }else{
                color[e[0]] = cur;
                color[e[1]] = cur;
                cur++;
            }
        }
        return {};
    }
};