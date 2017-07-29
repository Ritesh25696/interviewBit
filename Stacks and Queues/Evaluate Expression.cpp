
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

****************************************************************************************************************************

  int Solution::evalRPN(vector<string> &A) {
    stack<int> S;
    for(int i=0 ; i<A.size() ; i++){
        if(A[i] == "/"){
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            S.push(op1/op2);
        }
        else if(A[i] == "*"){
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            S.push(op1*op2);
        }
        else if(A[i] == "-"){
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            S.push(op1-op2);
        }
        else if(A[i] == "+"){
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            S.push(op1+op2);
        }
        else{
            S.push(stoi(A[i]));
            }
    }
    return S.top();
}
