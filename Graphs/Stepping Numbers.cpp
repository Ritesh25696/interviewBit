Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.

*********************************************************************************************************************************

void sn(int A , int B , int num , vector<int>& res){
    queue<int> Q;
    Q.push(num);
    while(!Q.empty()){
        int fr = Q.front();
        Q.pop();
        if(fr>=A && fr<=B)res.push_back(fr);
        if(fr == 0 || fr>B)continue;
        int ld = fr%10;
        int sna = fr*10+(ld-1);
        int snb = fr*10+(ld+1);
        if(ld == 0)Q.push(snb);
        else if(ld == 9)Q.push(sna);
        else{Q.push(sna);Q.push(snb);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i=0 ; i<=9 ; i++){
        sn(A , B , i , res);
    }
    sort(res.begin(),res.end());
    return res;
}
