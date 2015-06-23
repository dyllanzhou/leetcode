/*Basic Calculator II 
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function. 
*/
class Solution {
public:
    int calculate(string s) {
        stack<char>opStk;
        stack<long int>valStk;
        int op;
        long int n1,n2;
        for(int i = 0;i < s.size();){
            if(s[i] == ' '){
                ++i;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9'){
               int start = i;
               while(s[i] >= '0' && s[i] <= '9')++i;
               valStk.push(stol(s.substr(start,i - start)));
               if(!opStk.empty()){
                    if(opStk.top() == '*' || opStk.top() == '/'){
                       op = opStk.top();opStk.pop();
                       n2 = valStk.top();valStk.pop();
                       n1 = valStk.top();valStk.pop();
                       valStk.push(op == '*'?(n1*n2):(n1/n2));
                   }
                }
            }else {//op + - */
                if(s[i] == '*' || s[i] == '/'){
                    opStk.push(s[i++]);
                    continue;
                }
                if(!opStk.empty()){
                    op = opStk.top();opStk.pop();
                    n2 = valStk.top();valStk.pop();
                    n1 = valStk.top();valStk.pop();
                    valStk.push(op == '+'?(n1+n2):(n1-n2));      
                }else
                   opStk.push(s[i++]);
            }
        }
        while(!opStk.empty()){
            op = opStk.top();opStk.pop();
            n2 = valStk.top();valStk.pop();
            n1 = valStk.top();valStk.pop();
            valStk.push(op == '+'?(n1+n2):(n1-n2));
        }
        return valStk.top();
    }
};