class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        for(char x : s){
            if(!s1.empty() && s1.top() == x){
                s1.pop();
            }
            else{
                s1.push(x);
            }
        }
        string ans = "";
        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};