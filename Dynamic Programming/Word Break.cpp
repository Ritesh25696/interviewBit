Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

************************************************************************************************************************************ 

int dictionaryContains(string word, unordered_map<string,bool>& mymap)
{
     if(mymap.find(word) == mymap.end())return 0;
     else return 1;
}

int Solution::wordBreak(string str, vector<string> &B) {
    unordered_map<string,bool> mymap;
    for(int i=0 ; i<B.size() ; i++){
        mymap[B[i]] = true;
    }
    int size = str.length();
    if (size == 0)   return true;
 
    bool wb[size+1];
    memset(wb, 0, sizeof(wb));
    for (int i=1; i<=size; i++)
    {
        if (wb[i] == false && dictionaryContains( str.substr(0, i) , mymap))
            wb[i] = true;
 
        if (wb[i] == true)
        {
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i),mymap))
                    wb[j] = true;
 
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;

}
