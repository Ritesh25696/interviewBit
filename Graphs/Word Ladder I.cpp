Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

**************************************************************************************************************************************

bool isonediff(string a, string b){
    int k = 0;
    for(int i=0 ; i<a.length() ; i++){
        if(k > 1)return false;
        if(a[i] != b[i])
        k++;
    }
    if(k == 1)return true;
    return false;
}

int Solution::ladderLength(string start, string end, vector<string> &dict) {
    if(start == end)return 1;
    for(int i=0 ; i<dict.size() ; i++){
        if(dict[i] == start)dict.erase(dict.begin()+i);
    }
    queue<pair<string,int>>Q;
    Q.push(make_pair(start , 1));
    while(!Q.empty()){
        pair<string,int> fr = Q.front();
        Q.pop();
        for(int i=0 ; i<dict.size() ; i++){
            if(isonediff(fr.first,dict[i])){
                Q.push(make_pair(dict[i],fr.second+1));
                if(dict[i] == end)return fr.second+1;
                dict.erase(dict.begin()+i);
                i--;
            }
        }
    }
    return 0;
}
