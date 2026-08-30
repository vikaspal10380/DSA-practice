class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for(char x : s){
            if(x == '#'){
                if(!s1.empty()){
                    s1.pop();
                }  
            }
            else{
                s1.push(x);
            }
        }
        for(char x : t){
            if(x == '#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(x);
            }
        }
        if(s1 == s2){
            return true;
        }
        return false;
        
    }
};