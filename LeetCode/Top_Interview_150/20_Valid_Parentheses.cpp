class Solution {
public:
    bool isValid(string s) {
        stack<char> cadeia = {};
        for(char a : s){
            if(a == '(' || a == '[' || a == '{'){
                cadeia.push(a);
            }
            if(a == ')' || a == ']' || a == '}'){
                if(cadeia.empty()){
                    return false;
                }else{
                    if(cadeia.top() == a - 1 || cadeia.top() == a - 2){
                        cadeia.pop();
                    }else{
                        cadeia.push(a);
                    }
                }
            }
        }
        return cadeia.empty() ? true : false;
    }
};
