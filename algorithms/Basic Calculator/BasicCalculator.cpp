/*Basic Calculator
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function
*/
class Solution {
public:
    int calculate(string s) {
        stack<int>opStk,numStk;
        int start,op;
        for(int i = 0;i < s.size();){
            if(s[i] >='0' && s[i] <= '9'){
                start = i;
                while(s[i] >= '0' && s[i] <= '9')++i;
                numStk.push(stoi(s.substr(start,i - start)));
                if(opStk.empty())continue;
                op = opStk.top();
                if(op == '+' || op == '-'){
                    int num2 = numStk.top();numStk.pop();
                    int num1 = numStk.top();numStk.pop();
                    numStk.push(op == '+'?(num1+num2):(num1-num2));
                    opStk.pop();
                }
            }else{
                switch(s[i]){
                    case '(':opStk.push('(');break;
                    case ')':
                        opStk.pop();
                        if(!opStk.empty()){
                            op = opStk.top();
                            if(op == '+' || op == '-'){
                                int num2 = numStk.top();numStk.pop();
                                int num1 = numStk.top();numStk.pop();
                                numStk.push(op == '+'?(num1+num2):(num1-num2));
                                opStk.pop();
                             }
                        }
                        break;
                    case '+':
                    case '-':opStk.push(s[i]);break;
                    case ' ':
                    default:break;
                }
                ++i;
            }
        }
        return numStk.top();
    }
};