class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, co = 0, temp;
        while (numBottles > 0){
            res += numBottles;
            temp = numBottles;
            numBottles = (numBottles+co)/numExchange;
            co = (temp+co) % numExchange;
        }
        return res;
    }
};