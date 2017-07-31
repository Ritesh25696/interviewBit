Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")


***********************************************************************************************************

bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
 

void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart, 
                   int start, int n, string str)
{
    if (start >= n)
    {
        allPart.push_back(currPart);
        return;
    }
 
    for (int i=start; i<n; i++)
    {
        if (isPalindrome(str, start, i))
        {
            currPart.push_back(str.substr(start, i-start+1));
            allPalPartUtil(allPart, currPart, i+1, n, str);
             
            currPart.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string str) {
    int n = str.length();
    vector<vector<string> > allPart;
    vector<string> currPart; 
    allPalPartUtil(allPart, currPart, 0, n, str);
    return allPart;
    
}
