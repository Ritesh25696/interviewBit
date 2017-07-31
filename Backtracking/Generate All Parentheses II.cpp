Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

********************************************************************************************************

void helper(vector<string> &res, string str, int A, int open, int close, int i){
    if(close == A){
        res.push_back(str);
        return;
    }
    if(open > close){
        str.push_back(')');
        helper(res,str,A,open , close+1 , i+1);
        str.pop_back();
    }
    if(open<A){
        str.push_back('(');
        helper(res,str,A,open+1,close,i+1);
        str.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) {
    string str;
    vector<string> res;
    helper(res ,str, A , 0 , 0 , 0);
    reverse(res.begin(),res.end());
    return res;
}
