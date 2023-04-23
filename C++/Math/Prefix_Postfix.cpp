#include<bits/stdc++.h>

using namespace std;

double evaluatePrefix(string expr) {
    stack<double> st;
    int sz = (int)expr.size();
    for (int i = sz - 1; i >= 0; --i) {
        char c = expr[i];
        
        if (isdigit(c)) st.push(c - '0');
        
        else {
            double op1 = st.top(); st.pop();
            double op2 = st.top(); st.pop();
            
            switch(c) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                default:
                    cout << "Invalid operator\n";
                    return 1;
            }
        }
    }
    return st.top();
}

double evaluatePostfix(string expr) {
    stack<double> st;
    int sz = (int) expr.size();
    for (int i = 0; i < sz; i++) {
        char c = expr[i];

        if (isdigit(c)) st.push(c - '0');
        
        else {
            double op2 = st.top(); st.pop();
            double op1 = st.top(); st.pop();
            
            switch(c) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
                default:
                    cout << "Invalid operator\n";
                    return 1;
            }
        }
    }
    
    return st.top();
}

int main() {
    string prefixExpr = "*+23-45";
    string postfixExpr = "3 * 5 - 10 1 4 + / -";
    
    cout << "Prefix expression: " << prefixExpr << endl;
    cout << "Result: " << evaluatePrefix(prefixExpr) << endl;
    
    cout << "Postfix expression: " << postfixExpr << endl;
    cout << "Result: " << evaluatePostfix(postfixExpr) << endl;
    
    return 0;
}

