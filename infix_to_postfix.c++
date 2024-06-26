#include <iostream>
#include <stack>
using namespace std;
 
bool isOperatorOrNot(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
    {
        return true;
    }
 
    return false;
}
int precedence(char c)
{
    if (c == '^')
 
    {
        return 3;
    }
 
    else if (c == '/' || c == '*')
    {
        return 2;
    }
 
    else if (c == '+' || c == '-')
    {
        return 1;
    }
 
    else
    {
        return -1;
    }
}
 
string asscoiativity(char c)
{
    if (c == '^')
    {
        return "RTL";
    }
    return "LTR";
}
 
int main()
{
    string exp = "8+3*(9-6)/2^2+6/2";
    stack<char> st;
    string postfix;
 
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperatorOrNot(exp[i]))
        {
            postfix = postfix + exp[i];
        }
        else if (exp[i] == '(')
        {
            st.push('(');
        }
        else if (exp[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.pop();
        }
        else
 
        {
            while ((!st.empty() && precedence(exp[i]) < precedence(st.top())) ||
                   ((!st.empty() && precedence(exp[i]) == precedence(st.top())) && (!st.empty() && asscoiativity(exp[i]) == "LTR")))
 
            {
 
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
 
    while (!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }
    cout << "Postfix operation is:" << postfix << endl;
}