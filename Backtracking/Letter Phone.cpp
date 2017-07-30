Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

**************************************************************************************************************************************************

string values(int a){
    switch(a){
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return "";
        
    }
}

void helper(vector<string> &res , vector<string> &data ,string s , int i ){
    if(i == data.size()){
        res.push_back(s);
        return;
    }
    s+="z";
    for(int j=0 ; j<data[i].length() ; j++){
        s[i] = data[i][j];
        helper(res , data, s , i+1);
    }
} 

vector<string> Solution::letterCombinations(string A) {
      vector<string> data;
      vector<string> res;
      string s = "";
      for(int i=0 ; i<A.length() ; i++) data.push_back(values(A[i]-'0'));
      helper(res , data, s , 0 );
    return res;
}
