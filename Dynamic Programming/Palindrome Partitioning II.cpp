Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example : 
Given 
s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*****************************************************************************************************************************************************************************

int Solution::minCut(string str) {
   int n = str.length();
    int C[n];
    bool P[n][n];
  
    int i, j, k, L; 
  
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
    }
    for (L=2; L<=n; L++)
    {
        for (i=0; i<n-L+1; i++)
        {
            j = i+L-1; 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
        }
    }
 
    for (i=0; i<n; i++)
    {
        if (P[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for(j=0;j<i;j++)
            {
                if(P[j+1][i] == true && 1+C[j]<C[i])
                    C[i]=1+C[j];
            }
        }
    }
    return C[n-1];
}
