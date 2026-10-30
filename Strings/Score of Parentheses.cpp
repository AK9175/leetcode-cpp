class Solution {
public:

    int solve(int &i, string &s){
        int score = 0;
        while(i < s.length()){
            char ch = s[i++];
            if(ch == ')') return score;

            int inner = solve(i, s);

            if(inner == 0){
                score += 1;
            }
            else{
                score += 2 * inner;
            }
        }

        return score;
    }

    int scoreOfParentheses(string s) {
        int i = 0;
        return solve(i, s);
    }
};
