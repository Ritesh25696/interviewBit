Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

****************************************************************************************************************************************************

int Solution::isValid(string A) {
    stack<char> S;
    for(int i=0 ; i<A.length() ; i++){
        if(A[i] == '[' || A[i] == '{' || A[i] == '(') S.push(A[i]);
        else if(A[i] == ']'){
            if( S.empty() || S.top() != '[')return 0;
            S.pop();
        }
        else if(A[i] == '}'){
            if(S.empty() || S.top() != '{' )return 0;
            S.pop();
        }
        else if(A[i] == ')'){
            if(S.empty() || S.top() != '('  )return 0;
            S.pop();
        }
    }
    if(S.empty())return 1;
    return 0;
}
