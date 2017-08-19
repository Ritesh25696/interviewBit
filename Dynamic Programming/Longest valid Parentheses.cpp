Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

**************************************************************************************************************

int Solution::longestValidParentheses(string str) {
    int n = str.length();
 
    stack<int> stk;
    stk.push(-1);
    int result = 0;
 
    for (int i=0; i<n; i++)
    {
        if (str[i] == '(')
          stk.push(i);
 
        else 
        {
            stk.pop();
 
            if (!stk.empty())
                result = max(result, i - stk.top());
            else stk.push(i);
        }
    }
    return result;
}
