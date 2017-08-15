Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert 

****************************************************************************************************************************

int Solution::minDistance(string A, string B) {
   if(A.length() == 0)return B.length();
   if(B.length() == 0)return A.length();
   if(A == B)return 0;
   int dis[A.length()+1][B.length()+1];
   for(int i=0 ; i<=A.length() ; i++)
   dis[i][0] = i;
   for(int j=0 ; j<= B.length() ; j++)
   dis[0][j] = j;
   for(int i=1 ; i<=A.length() ; i++){
       for(int j=1 ; j<=B.length() ; j++){
           if(A[i-1] == B[j-1])dis[i][j]=dis[i-1][j-1];
           else{
               dis[i][j] = min(dis[i-1][j-1],min(dis[i-1][j],dis[i][j-1]))+1;
           }
       }
   }
   return dis[A.length()][B.length()];
}
