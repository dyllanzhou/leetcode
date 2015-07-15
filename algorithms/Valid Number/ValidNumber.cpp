/*Valid Number
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
*/
class Solution {
public:
    bool isNumber(string s) {//"+.8  "46.e3" .e1 " 005047e+6  4e+
         int size = s.size();
         int i,j;
         for(i = 0;i < s.size() && s[i] == ' ';++i);
         for(j = size - 1;j > -1 && s[j] == ' ';--j);
         if(i > j)return false;
         int state = 0;//0:start,1:+-,2:digit,3:   10:error
         for(int k = i;k <= j;k++){
             switch(state){
                 case 0://start
                      if(s[k] >= '0' && s[k] <= '9')state = 2;
                      else if(s[k]=='+' || s[k] == '-')state = 1;
                      else if(s[k] == '.' && (k+1) <= j)state = 11;
                      else state = 10;
                      break;
                 case 1: //+-
                      if(s[k] >= '0' && s[k] <= '9')state = 2;
                      else if(s[k] == '.' && (k+1) <= j)state = 11;
                      else state = 10;
                      break;
                 case 2://0-9
                      if(s[k] >= '0' && s[k] <= '9')state = 2;
                      else if(s[k] == '.')state = 21;
                      else if(s[k] == 'e'&& (k+1) <= j)state = 22;
                      else state = 10;
                      break;
                 case 11://only . no digit 
                        if(s[k] >= '0' && s[k] <= '9')state = 21;
                        else state = 10;
                        break;
                 case 21://.
                      if(s[k] >= '0' && s[k] <= '9')state = 21;
                      else if(s[k] == 'e'&& (k+1) <= j)state = 22;
                      else state = 10;
                      break;
                case 22://e
                      if(s[k] >= '0' && s[k] <= '9')state = 22;
                      else if((s[k] == '+' || s[k] == '-') && s[k-1] == 'e' && (k+1)<=j)state = 22;
                      else state = 10;
                      break;                   
                case 10:
                      return false;
             }
         }
         return state != 10;
    }
};