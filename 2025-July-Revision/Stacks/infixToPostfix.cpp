#include <bits/stdc++.h>

using namespace std;

int getPrec(char ch){
    switch(ch){
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;

    }
    return -1;
}

string conv(string infix){
    stack<char> st;
    string res;

    for(char ch : infix){
        int prc = getPrec(ch);
        if(prc == -1){
            if(ch == ')'){
                while(st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }else if(ch == '('){
                st.push(ch);
            }else res += ch;


            continue;
        }
        
        while(!st.empty() && getPrec(st.top()) >= getPrec(ch)){
            if(st.top() == '(')break;
            res += st.top();
            st.pop();
        }
        st.push(ch);
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }


    return res;
}

int main(){
    string infixExp;
    cin >> infixExp;

    cout << conv(infixExp);
}