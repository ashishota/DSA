#include <iostream>
#include<stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(int i=0;i<s.size();i++) {
                switch(s[i]){
                    case '(':
                    case '{':
                    case '[':
                        st.push(s[i]);
                        break;
                    case ')':
                        if(!st.empty() && st.top() == '(') {
                            st.pop();
                        } else {
                            st.push(s[i]);
                        }
                        break;
                    case '}':
                        if(!st.empty() && st.top() == '{') {
                            st.pop();
                        } else {
                            st.push(s[i]);
                        }
                        break;
                    case ']':
                        if(!st.empty() && st.top() == '[') {
                            st.pop();
                        } else {
                            st.push(s[i]);
                        }
                        break;
                }
            }
            if(!st.empty()) {
                return false;
            } 
    
            return true;
        }
};



int main() {
    Solution sol;
    string s;
    
    cout << "Enter a string containing brackets: ";
    cin >> s;

    if (sol.isValid(s)) {
        cout << "The string has valid parentheses.\n";
    } else {
        cout << "The string has invalid parentheses.\n";
    }

    return 0;
}
