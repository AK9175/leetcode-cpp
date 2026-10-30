// 1096. Brace Expansion II  [Hard]
//"a{b,c}{d,e}f{g,h}"
//"a{b,c}{d,e}{fg, fh}
//{ab,ac}{d,e}{fg,fh}
//{abd,abe, acd, ace}{fg,fh}
//{abdfg, abdfh, abefg, abefh, acdfg, acdfh, acefg, acefh}
// "{{a,z},a{{f{{b,c},s{t}}}}}"
class Solution {
public:

    void solve(vector<set<string>> &operands,  vector<char> &operators){
        int left = operands.size()-2;
        int right = operands.size()-1;
        if(operators.back() == '+'){
            operands[left].merge(operands[right]);
        }
        else{
            set<string> tmp;
            for(auto &it : operands[left]){
                for(auto &it1 : operands[right]){
                    tmp.insert(it + it1);
                }
            }
            operands[left] = tmp;
        }
        operands.pop_back();
    }

    vector<string> braceExpansionII(string expression) {
        vector<set<string>> operands;
        vector<char> operators;

        for(int i = 0 ; i < expression.length() ; i++){
            if(expression[i] == '{'){
                if(i > 0 && (expression[i-1] == '}' || isalpha(expression[i-1]))){
                    operators.push_back('*');
                }
                operators.push_back('{');
            }
            else if(expression[i] == ','){
                while(operators.size() && operators.back() == '*'){
                    solve(operands, operators);
                    operators.pop_back();
                }
                operators.push_back('+');
            }
            else if(expression[i] == '}'){
                while(operators.size() && operators.back() != '{'){
                    solve(operands, operators);
                    operators.pop_back();
                }
                operators.pop_back();
            }
            else{
                if(i > 0 && (expression[i-1] == '}' || isalpha(expression[i-1]))){
                    operators.push_back('*');
                }
                operands.push_back({string(1, expression[i])});
            }
        }

        while(!operators.empty()){
            solve(operands, operators);
            operators.pop_back();
        }

        return {operands.back().begin(), operands.back().end()};
    }
};
