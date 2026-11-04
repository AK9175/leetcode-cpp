class Solution {
public:

    multiset<long long> left;
    multiset<long long> right;

    void rebalance(){
        while(left.size() > right.size() + 1){
            auto leftend = prev(left.end());
            right.insert(*leftend);
            left.erase(leftend);
        }
        while(right.size() > left.size()){
            auto rightstart = right.begin();
            left.insert(*rightstart);
            right.erase(rightstart);
        }
    }

    void add(int value){
        if(left.empty() || value <= *left.rbegin()){
            left.insert(value);
        }
        else{
            right.insert(value);
        }

        rebalance();
    }

    void remove(int value){
        auto ileft = left.find(value);
        if(ileft != left.end()){
            left.erase(ileft);
        }
        else{
            auto iright = right.find(value);
            right.erase(iright);
        }
        rebalance();
    }

    double getMedian(int k){
        if(k % 2 == 1){
            return double(*left.rbegin());
        }
        return double(*left.rbegin() + *right.begin())/2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for(int i = 0 ; i < k ; i++){
            add(nums[i]);
        }
        ans.push_back(getMedian(k));
        int i = 0, j = k;
        while(j < nums.size()){
            remove(nums[i]);
            add(nums[j]);
            ans.push_back(getMedian(k));
            i++;
            j++;
        }

        return ans;
    }
};
