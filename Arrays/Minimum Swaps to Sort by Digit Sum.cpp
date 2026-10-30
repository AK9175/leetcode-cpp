class Solution {
public:
    int digitSum(int val) {
        int sum = 0;

        while(val > 0){
            sum += val % 10;
            val = val / 10;
        }

        return sum;
    }

    int cycle(unordered_map<int, int> &map, int src, int dst, vector<bool> &visited, int cnt){
        if(visited[src]) return cnt;
        visited[src] = true;
        if(src == dst) return cnt;
        cnt++;
        return cycle(map, dst, map[dst], visited, cnt);
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> sorted;
        vector<bool> visited(nums.size(), false);
        for(int num : nums){
            sorted.push_back({digitSum(num), num});
        }

        sort(sorted.begin(), sorted.end());
        unordered_map<int, int>smap,nmap,map;
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            smap[sorted[i].second] = i;
            nmap[nums[i]] = i;
        }

        for(auto itr : nmap){
            map[itr.second] = smap[itr.first]; 
        }

        for(auto itr : map){
            int src = itr.first;
            int dst = itr.second;
            if(visited[src] || src == dst) continue;
            ans += cycle(map, src, dst, visited, 0)-1;
        }
        // cout<<"A";
        return ans;
    }
};