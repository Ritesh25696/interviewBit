Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

**********************************************************************************************************

int Solution::isInterleave(string A, string B, string C) {
      if(C.length() != A.length()+B.length()){return 0;}
    int i=0, j=0 ,k=0;
    while(k < C.length()){
        if(C[k] != A[i] && C[k] != B[j]){
               return 0;}
        if(C[k] == A[i] && C[k] == B[j]){
            int initiali = i, initialj = j;
            while(C[k] == A[i] && C[k] == B[j]){
                k++;i++;j++;
            }
            if(C[k] == A[i]){
                j = initialj;
            }
            else{
                i = initiali;
            }
        }
        else if(i<A.length() && C[k] == A[i]){i++;k++;}
        else{j++;k++;}

    }
    return 1;
}
