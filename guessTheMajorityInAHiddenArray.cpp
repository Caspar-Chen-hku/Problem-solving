class Solution {
public:
    int guessMajority(ArrayReader &rd) {
        vector<int> a, q;
        int has4 = false, has2 = false, sz = rd.length(), cnt = 0, b = 0;
        for (int i = 0; i < 5; ++i) {
            q.push_back(rd.query(i == 0 ? 1 : 0, i <= 1 ? 2 : 1, 
                i <= 2 ? 3 : 2, i <= 3 ? 4 : 3));
            has4 |= q.back() == 4;
            has2 |= q.back() == 2;
        }
        for (auto i = 0; i < q.size(); ++i)
            if (q[i] == (has4 ? (has2 ? 2 : 4) : 0)) {
                ++cnt;
                a.push_back(i);
            }
            else
                b = i;
        for (auto i = 5; i < sz - 1; i += 2) {
            auto res = rd.query(a[0], a[1], i , i + 1);
            cnt += res / 2;
            if (res == 0)
                b = i;
        }
        if (sz % 2 == 0)
            cnt += rd.query(a[0], a[1], a[2] , sz - 1) / 4;
        return cnt == (sz - cnt)  ? -1 : cnt > (sz - cnt) ? a[0] : b;
    }
};