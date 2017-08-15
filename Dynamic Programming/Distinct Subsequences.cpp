Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

 Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none ) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Example :
 S = "rabbbit" T = "rabbit" 

Return 3. And the formations as follows:

S1= "ra_bbit" 
S2= "rab_bit" 
S3="rabb_it"
"_" marks the removed character.

***********************************************************************************************************************

int Solution::numDistinct(string S, string T) {
   int m = T.length(), n = S.length();
 
    if (m > n)
        return 0;
 
     int mat[m + 1][n + 1];
     for (int i = 1; i <= m; i++)
        mat[i][0] = 0;
 
    for (int j = 0; j <= n; j++)
        mat[0][j] = 1;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (T[i - 1] != S[j - 1])
                mat[i][j] = mat[i][j - 1];
 
            else
                mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
        }
    }
 
    return mat[m][n] ;
}
