Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Examples :

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "*") → 1
isMatch("aa", "a*") → 1
isMatch("ab", "?*") → 1
isMatch("aab", "c*a*b") → 0

************************************************************************************************************************

int Solution::isMatch(const string &str, const string &p) {
    string pattern = "";
    for(int i=0 ; i<p.length() ; i++){
        if(i != 0 && p[i] == '*' && p[i-1] == '*')continue;
        else pattern+=p[i];
    }
      int n = str.length();
      int m = pattern.length();
      if (m == 0)
        return (n == 0);
   bool lookup[n + 1][m + 1];
   memset(lookup, false, sizeof(lookup));
   lookup[0][0] = true;
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] ||
                               lookup[i - 1][j];
 
            else if (pattern[j - 1] == '?' ||
                    str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
 
            else lookup[i][j] = false;
        }
    }
 
    return lookup[n][m];
}
