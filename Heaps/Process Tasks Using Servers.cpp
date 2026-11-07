class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> free;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;//<endtime, weight,index>
        long long left = 0, right = 0, n = servers.size(), m = tasks.size();
        vector<int> ans(m, 0);
        for(int i = 0 ; i < n ; i++){
            free.push({servers[i], i});
        }

        while(left < m){
            //Free the busy servers
            if(free.empty()){
                right = busy.top()[0];
            }

            while(!busy.empty() && busy.top()[0] == right){
                free.push({busy.top()[1], busy.top()[2]});
                busy.pop();
            }

            //Server gets the task.
            while(!free.empty() && left < m && left <= right){
                long long endtime = right + tasks[left];
                auto itr = free.top();
                free.pop();
                busy.push({endtime, itr.first, itr.second});
                ans[left] = itr.second;
                left++;
            }
            right++;
        }

        return ans;
    }
};

//So at anuy given particular second you have to do 2 things, queue in now free servers, 
//And queue out servers to tasks in the Task queue
//task queue will be nothing but a pointer at left, signifying what all tasks got server, 
//and a right pointer signifying current time
//so at any given index (right) check left, if right - left > 1, that means few tasks need server
//then check from server pq if any server is available, if yes then assign, if no then skip and move the right pointer
//also before starting each task maintain the end time some where(map), when you hit the end time in the map, free that server
//(key)"endtime" : array of <server_id>
//iterate on them all to free them up, and freeing means adding back to the pq;

//server pq will be <weight, index>