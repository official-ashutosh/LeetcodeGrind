class Solution {
public:
    string decodeString(string s) {
        stack<int>numst;
        stack<string>strst;
        int num = 0;
        string curstr = "";
        for(char ch :s){
            if(isdigit(ch)){
              num = num*10 + (ch-'0');
            }else if(ch == '['){
                numst.push(num);
                strst.push(curstr);
                num = 0;
                curstr = "";
            }else if(ch == ']'){
                int repeat = numst.top();
                string top = strst.top();
                numst.pop();
                strst.pop();
                while(repeat --){
                    top += curstr;
                }
                curstr = top;
            }else{
                curstr += ch;
            }
        }
        return curstr;
    }
};