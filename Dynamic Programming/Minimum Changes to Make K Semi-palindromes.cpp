class Solution {
public:

    int minCostPalindrome(string s, int d){
        int left = 0, right = s.length()-1, cost = 0;
        while(left <= right){
            if(s[left] != s[right]) cost++;
            left++, right--;
        }
        return cost;
    }

    vector<int> calculateDivisors(int n){
        vector<int> divisors;
        for(int i = 1 ; i*i <= n ; i++){
            if(n%i == 0){
                divisors.push_back(i);
                if(i*i != n){
                    divisors.push_back(n/i);
                }
            }
        }
        return divisors;
    }

    int minimumCost(string s){
        int n = s.length();
        int mini = INT_MAX;
        vector<int> divisors = calculateDivisors(n);
        for(int i = 0 ; i < divisors.size() ; i++){
            int count = 0;
            if(divisors[i] < n){
                vector<string> ss(divisors[i],""); 
                for(int j = 0 ; j < n ; j++){
                    ss[(j+1)%divisors[i]].push_back(s[j]);
                }
                for(int j = 0 ; j < ss.size() ; j++){ 
                    count += minCostPalindrome(ss[j], divisors[i]);
                }
                mini = min(mini, count);
            }
        }
        return mini;
    }

    int solve(int ind, int minlen, int maxlen, vector<vector<int>> &cost, int k, int n, vector<vector<int>> &dp){
        if(k == 1) return cost[ind][n-1];
        if(dp[ind][k] != INT_MAX) return dp[ind][k];
        for(int j = minlen ; j <= maxlen ; j++){
            int currcost = 0;
            currcost += cost[ind][ind+j-1];
            currcost += solve(ind+j, 2, (n-(ind+j))-(k-2)*2, cost, k-1, n, dp);
            dp[ind][k] = min(dp[ind][k], currcost);
        }
        return dp[ind][k];
    }

    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n , INT_MAX));
        //Calculate the minimum cost of making each substring a semi-palindrome first, not that down in a Cost grid
        //cost[i][j] means cost of converting substring from index i to j in a semi-palindorme
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                cost[i][j] = minimumCost(s.substr(i, j-i+1));
            }
        }

        //Use recursion and memoization to get the overall minimum (partition dp probably)
        //Calculate min and max length of substring there can be minimum is 2, and maximum is s.length() - (k-1)*2
        //for memoization we can use states 
        //dp[i][k], i is where the index starts in string(consider as starting), and k is the splits left 
        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));
        int minlen = 2, maxlen = n - (k-1)*2;
        return solve(0, minlen, maxlen, cost, k, n, dp);

    }
};
