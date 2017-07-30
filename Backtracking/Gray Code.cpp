The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

*****************************************************************************************************************************************

void generateGrayCode(int n, vector<int> &v){
    if(n==1){
        v.push_back(0);
        v.push_back(1);
        return;
    }
    generateGrayCode(n-1,v);
    int m=v.size();
    int two=1;
    int i=1;
    while(i<n){
        two=two<<1;
        i++;
    }
    for(i=m-1;i>=0;i--)
        v.push_back(v[i]|two);
    
}
vector<int> Solution::grayCode(int A) {
    vector<int> v;
    if(A==0){
        v.push_back(0);
        return v;
    }
    generateGrayCode(A,v);
    return v;
}
