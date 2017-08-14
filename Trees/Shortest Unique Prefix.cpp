Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always 

****************************************************************************************************************

vector<string> Solution::prefix(vector<string> &A) {
    unordered_map<string , int> my_map;
    vector<string> B;
    for(int i=0 ; i<A.size() ; i++){
        for(int j=1 ; j<=A[i].length() ; j++){
        string s = A[i].substr(0, j);
        if(my_map.find(s) == my_map.end()){
        my_map[s] = i;
        B.push_back(s);
        break;
        }
        else if(my_map.find(s) != my_map.end()){
            int k = my_map[s];
            for(int z = s.length()+1 ; z<=A[k].length() ; z++){
            string p = A[k].substr(0, z);
            if(my_map.find(p) == my_map.end()){
            my_map[p] = k;
            B[k] = p;
            break;
        }    
        }
        }
    }
}
return B;
}
