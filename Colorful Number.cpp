For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

***************************************************************************************************************************

bool check(vector<int> &digits, unordered_map<long long int , bool>&rel , int l){
    int pro = 1,p=0;
    for(int i=0 ; i<l-1 ; i++)
    pro*=digits[i];
    for(int i=l-1 ; i<digits.size() ; i++){
        if(digits[i] == 0 && digits.size()>1)return 0;
        pro*= digits[i];
        if(rel.find(pro) != rel.end())return 0;
        rel[pro] = true;
        pro /= digits[p];
        p++;
    }
    return 1;
}

int Solution::colorful(int A) {
    vector<int> digits;
    unordered_map<long long int , bool> rel;
    while(A>0){
        digits.push_back(A%10);
        A /= 10;
    }
    for(int i=1 ; i<=digits.size() ; i++){
        if(!check(digits , rel , i))return 0;
    }
    return 1;
}
