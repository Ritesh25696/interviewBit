Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is
 [ "cat sand dog", "cats and dog" ] 

Make sure the strings are sorted in your result.

*********************************************************************************************************************************

void wordbreakutil(string A,unordered_set<string> mymap,string r, vector<string> & res){
    for(int i=1 ; i<=A.length() ; i++){
        string pre  = A.substr(0,i);
        if(mymap.find(pre) != mymap.end()){
            if(i == A.length()){
                r+=pre;
                res.push_back(r);
                return;
            }
                wordbreakutil(A.substr(i,A.size()-i), mymap , r+pre+" ",res);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
   unordered_set<string> mymap;
   for(int i=0 ; i<B.size() ; i++)
   mymap.insert(B[i]);
   string r = "";
   vector<string> res;
   wordbreakutil(A,mymap,r,res);
   return res;
}
