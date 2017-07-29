Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

****************************************************************************************************************

int Solution::braces(string A) {
   stack<bool> S;
   for(int i=0 ; i<A.length() ; i++){
       if(A[i] == '(' && A[i+1] == '('){
           S.push(true);
       } 
       else if(A[i] == '('){
           S.push(false);
       }
       else if(A[i] == ')' && A[i-1] == ')'){
           if(S.top() == true)return 1;
           else S.pop();
       }
       else if(A[i] == ')'){
           if(A[i-2] == '(')return 1;
           S.pop();
       }
   }
   return 0;
}
