Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"

*******************************************************************************************************************

string Solution::reverseString(string A) {

   if(A.length() < 2)return A;
   
   stack<char> S;
   for(int i=0 ; i<A.length() ; i++){
       S.push(A[i]);
   }
   for(int i=0 ; i<A.size() ; i++){
       A[i] = S.top();
       S.pop();
   }
   return A;
}
