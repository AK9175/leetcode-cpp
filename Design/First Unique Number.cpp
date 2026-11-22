// 1429. First Unique Number  [Medium]

class FirstUnique {
public:
    queue<pair<int, int>> q;
    unordered_map<int, int> mp;
    FirstUnique(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            q.push({nums[i], 1});
            mp[nums[i]]++;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty()){
            if(mp[q.front().first] != q.front().second) q.pop();
            else break;
        }
        if(!q.empty()) return q.front().first;
        return -1;
    }
    
    void add(int value) {
        mp[value]++;
        q.push({value, 1});
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

 
//tbh we dont care when number becomes non unique
//so in a map we maintain original freq of a number
// and when the showFirstUnique is asked, we will first check the top of
//queue, and then compare that element in top of the queue with its freq in 
//actual freq map, and if in freq map is not unique just push the element out 
//and pop untill the freq in freq map matches with the cureent freq in queue
//and ofc that freq should be 1