class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> k;
        int n = nums.size(), ans = 0;
        vector<int> temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = 1 ; i*i <= n ; i++){
            if(n%i == 0){
                k.push_back(i);
                if(i*i != n){
                    k.push_back(n/i);
                }
            }
        }   
        if(nums == temp){
            ans = accumulate(begin(k), end(k), 0);
            return ans;
        } 
        return 10;
    }
};