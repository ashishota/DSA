#include<iostream>
#include<stack>

using namespace std;

class Solution {
    public:
        int longestValidParentheses(string s) {
            if(s.empty()) return 0;

            stack<char> st;
            for(int i=0;i<s.size();i++) {
                if(s[i] == '(') {
                    
                    
                } else {
                    
                }
                    
            }
            return st.size();
    
        }
};

int main() {
    string s = "()(()()())";
    Solution code;
    int res = code.longestValidParentheses(s);
    cout<<res<<endl;
}