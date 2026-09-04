#include<iostream>
#include<stack>
using namespace std;

// 1. Use stack, to check given string is palindrome or not

bool PalindromeCheck(string val) {
    stack<char> st;
    int len = val.length();
    int isOddLength = len & 1; // len % 2 != 0
    cout << "isOdd length : " << (isOddLength ? "true" : "false") << endl;

    int i = 0;
    while(i < (len / 2)) st.push(val[i++]); 
    
    if(isOddLength) st.push(val[i]);

    while(i < len && !st.empty() && st.top() == val[i] ){
        cout << "st.top()  = " << st.top() << " and val[i] = " <<  val[i] << endl;
        i++;
        st.pop();
    }

    return st.empty();
}

int main() {
    string val;
    cout<<"Enter a string: ";
    cin>>val;

    if(PalindromeCheck(val)) cout<<" It is palindrome. " << endl;
    else cout<< " It is not palindrome" << endl;

    return 0;
}