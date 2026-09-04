#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 2. check the given string is Balanced parenthesis or not (use stack)  {{[]()()[]}}
// {{(()}}

bool isBalancedParanthesis(string expresion){
     stack<char> st;

     for(auto &it : expresion){
        if(it == '(' || it == '{' || it == '[') st.push(it);
        if(st.empty()) return false;
        else if(it == ')' && st.top() == '(') st.pop();
        else if(it == '}' && st.top() == '{') st.pop();
        else if(it == ']' && st.top() == '[') st.pop();
     }
     return st.empty();
}

int main(){
    string expresion;
    cout << "Enter the expression : ";
    cin >> expresion;

    if(isBalancedParanthesis(expresion))cout << "given expresion -> " << expresion << " has balanced parantheis" << endl;
    else cout << "given expresion -> " << expresion << " has not balanced parantheis" << endl;
    return 0;
}