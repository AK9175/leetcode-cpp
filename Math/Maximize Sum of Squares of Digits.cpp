class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9 < sum) return "";
        string ans = "";
        while(num && sum){
            if(sum >= 9){
                ans += '9';
                sum -= 9;
            }
            else {
                ans += to_string(sum);
                sum -= sum;
            }
            num--;
        }
        
        while(num){
            ans += '0';
            num--;
        }

        return ans;
    }
};

// 999

// 9, n=3
// 900

// Input: num = 2, sum = 17

// Output: "98"

// Explanation:

// There are 2 good integers: 89 and 98.

// The score of 89 is 82 + 92 = 145.
// The score of 98 is 92 + 82 = 145.