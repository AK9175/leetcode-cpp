// 4055. Count Shadow Pairs II  [Hard]

class Solution {
public:
    int shadowPairs(vector<int>& nums) {
        stack<int> s;
        s.push(nums[0]);
        int ans = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            while(!s.empty() && s.top() > nums[i]){
                s.pop();
            }
            if(!s.empty()) ans++;
            s.push(nums[i]);
        }

        
    }
};
