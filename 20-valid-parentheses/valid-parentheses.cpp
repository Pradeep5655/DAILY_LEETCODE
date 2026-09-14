class Solution {
public:
    bool isValid(string s) {
        stack<char> X;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                X.push(s[i]);
            } 
            else {
                if (X.empty()) {
                    return false;
                }
                
                char top = X.top();
                if ((s[i] == ']' && top == '[') || 
                    (s[i] == '}' && top == '{') || 
                    (s[i] == ')' && top == '(')) {
                    X.pop(); 
                } else {
                    return false; 
                }
            }
        }
        return X.empty();
    }
};