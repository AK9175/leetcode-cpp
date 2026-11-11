class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long commonreq = min(need1, need2);
        long long x=0,y=0;
        x = min(costBoth * commonreq, cost1*commonreq + cost2*commonreq);
        if(need1 > need2){
            long long leftover = need1 - need2;
            y = min(leftover*cost1, costBoth*leftover);
        }
        else{
            long long leftover = need2 - need1;
            y = min(leftover*cost2, costBoth*leftover);
        }
        return x+y;
    }
};
