// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings  [Medium]

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int totalDepth = 0, count = 0;
        for(int i = 0 ; i < seq.length() ; i++){
            if(seq[i] == '(') count++;
            else count--;
            totalDepth = max(totalDepth, count);
        }
        int depthA = 0, depthB = 0;
        vector<int> ans(seq.length(), 0);
        if(totalDepth % 2 == 0){
            depthA = totalDepth/2;
            depthB = depthA;
        }
        else{
            depthA = totalDepth/2 + 1;
            depthB = totalDepth - depthA;
        }

        int depth = 0;
        for(int i = 0 ; i < seq.length() ; i++){
            if(seq[i] == '('){
                depth++;
                if(depth > depthA){
                    ans[i] = 1;
                }
            }
            else{
                if(depth > depthA){
                    ans[i] = 1;
                }
                depth--;
            }
        }

        return ans;
    }
};
