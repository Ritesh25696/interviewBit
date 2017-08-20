Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*******************************************************************************************************************************************************************************

int Solution::isMatch(const string &s, const string &p) {
    bool A[s.length()+1][p.length()+1];
    for(int i=1 ; i<=s.length() ; i++)A[i][0] = false;
    A[0][0] = true;
    for(int j=1 ; j<=p.length();j++){
        if(p[j-1] == '*')A[0][j] = A[0][j-2];
        else A[0][j] = false;
    }
    for(int i=1; i<=s.length() ; i++){
        for(int j=1; j<=p.length(); j++){
            if(p[j-1] == s[i-1] || p[j-1] == '.'){
            A[i][j] = A[i-1][j-1];
            }
            
            else if(p[j-1] == '*'){
                A[i][j] = A[i][j-2];
                if(A[i][j] == false){
                if(p[j-2] == '.' || p[j-2] == s[i-1])
                A[i][j] = A[i-1][j];
                }
            }
            else {A[i][j] = false;}
        }
    }
    return A[s.length()][p.length()];
}
