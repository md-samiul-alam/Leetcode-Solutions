class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>stk;
        stack<char>operation;
        stk.push(expression[0]);
        bool lastExp = false;
        string temp = "";
        for(int i=0; i<expression.size(); ++i){
            if(expression[i] != ','){
                temp.push_back(expression[i]);
            }
        }
        expression = temp;
        int i=0;
        for(int i=0; i<expression.size(); ++i) {
            if(expression[i] == ')') {
                char op = operation.top();
                operation.pop();
                bool exp;
                if(op == '|') {
                    exp = false;
                    while(stk.top() != '(') {
                        exp |= (stk.top() == 'f' ? false : true);
                        stk.pop();
                    }
                    stk.pop();
                }
                else if(op == '&') {
                    exp = true;
                    while(stk.top() != '(') {
                        exp &= (stk.top() == 'f' ? false : true);
                        stk.pop();
                    }
                    stk.pop();
                }
                else { // handle ! case
                    exp = (stk.top() == 'f' ? true : false);
                    stk.pop();
                    stk.pop();
                }
                if(exp) {
                    stk.push('t');
                }
                else {
                    stk.push('f');
                }
                lastExp = exp;
            }
            else if(expression[i] == '|' || expression[i] == '&' || expression[i] == '!') {
                operation.push(expression[i]);
            }
            else {
                stk.push(expression[i]);
            }
        }
        return lastExp;
    }
};
