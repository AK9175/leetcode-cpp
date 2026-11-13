class Solution {
public:

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sumOfRunningMax(n, 0);
        vector<long long> prefixsum(n+1, 0);
        vector<int> nextGreaterIndex(n, 0);
        stack<int> st;
        long long ans = 0;
        st.push(0);
        prefixsum[0] = 0;
        prefixsum[1] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefixsum[i+1] = prefixsum[i] + nums[i];
            while(!st.empty() && nums[st.top()] <= nums[i]){
                nextGreaterIndex[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            nextGreaterIndex[st.top()] = n;
            st.pop();
        }

        for(int i = n-1 ; i >= 0 ; i--){
            if(nextGreaterIndex[i] == n){
                sumOfRunningMax[i] = (long long)nums[i] * (n - i);
            }
            else{
                sumOfRunningMax[i] = (long long)sumOfRunningMax[nextGreaterIndex[i]] + (long long)nums[i]*(nextGreaterIndex[i] - i);
            }
        }

        deque<int> dq;
        long long left = 0, right = 0;
        while(right < n){
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            //Shrink Left if it is invalid
            while(true){
                while(!dq.empty() && left > dq.front()){
                    dq.pop_front();
                }
                int maxIndex = dq.front();

                long long targetSum = sumOfRunningMax[left] - sumOfRunningMax[maxIndex] + (long long)nums[maxIndex]*(right - maxIndex + 1);

                long long actualWindowSum = prefixsum[right+1] - prefixsum[left];

                long long cost = targetSum - actualWindowSum;

                if(cost <= k) break; //If its still valid break out of this and increment on right

                left++;
            }

            ans += right - left + 1;

            right++;
        }

        return ans;

    }
};
