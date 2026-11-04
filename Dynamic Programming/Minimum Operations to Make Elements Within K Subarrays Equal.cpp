class Solution {
public:

    multiset<long long> left, right;
    vector<long long> cost;
    long long leftsum = 0, rightsum = 0;

    void rebalance(){
        while(right.size() + 1 < left.size()){
            auto leftend = prev(left.end());
            right.insert(*leftend);
            rightsum += *leftend;
            leftsum -= *leftend;
            left.erase(leftend);
        }

        while(right.size() > left.size()){
            auto rightstart = right.begin();
            left.insert(*rightstart);
            leftsum += *rightstart;
            rightsum -= *rightstart;
            right.erase(rightstart);
        }
    }

    void add(long long value){
        if(left.empty() || value <= *left.rbegin()){
            left.insert(value);
            leftsum += value;
        }
        else{
            right.insert(value);
            rightsum += value;
        }
        rebalance();
    }

    void remove(long long value){
        auto ileft = left.find(value);
        if(ileft != left.end()){
            left.erase(ileft);
            leftsum -= value;
        }
        else{
            auto iright = right.find(value);
            if(iright != right.end()){
                right.erase(iright);
                rightsum -= value; 
            }
        }
        rebalance();
    }

    long long getMedian(int k){
        if(k % 2 == 1){
            return *left.rbegin();
        }
        return round((*left.rbegin() + *right.begin())/2.0);
    }

    long long calculateCost(long long median, vector<int>& nums, int low, int high){
        long long lcost = 0, rcost = 0;
        lcost = median*left.size() - leftsum;
        rcost = rightsum - median*right.size();
        return lcost + rcost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        for(int i = 0 ; i < x ; i++){
            add(nums[i]);
        }
        cost.push_back(calculateCost(getMedian(x),nums, 0, x-1));
        int i = 0, j = x;
        while(j < nums.size()){
            remove(nums[i]);
            add(nums[j]);
            i++;
            cost.push_back(calculateCost(getMedian(x),nums, i, j));
            j++;
        }
        
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(k+1, LONG_MAX));
    
        for(int l = 0 ; l <= nums.size() ; l++){
            dp[l][0] = 0;
        }

        for(int l = x ; l <= nums.size() ; l++){
            for(int m = 1 ; m <= k ; m++){
                if(cost[l-x] != LONG_MAX && dp[l-x][m-1] != LONG_MAX){
                    dp[l][m] = min(dp[l-1][m], cost[l-x] + dp[l-x][m-1]);
                }
            }
        }
        return dp[nums.size()][k];
    }
};
