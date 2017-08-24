There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Example :
Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10
In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration. In each row first two numbers represent the islands number which are connected by this bridge and the third integer is the cost associated with this bridge.

In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with cost 3), 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible cost(1+3+2 = 6). 
In any other case, cost incurred will be more.

**************************************************************************************************************************************************************

bool func(vector<int> A , vector<int> B){
    return A[2]<B[2];
}

struct subset{
    int parent;
    int rank;
};

int find(vector<subset> &S, int x){
    if(S[x].parent != x)
    S[x].parent = find(S,S[x].parent);
    return S[x].parent;
}

void unio(vector<subset> &S , int x , int y){
    int xroot = find(S , x);
    int yroot = find(S , y);
    if(S[xroot].rank < S[yroot].rank)
    S[xroot].parent = yroot;
    else if (S[xroot].rank > S[yroot].rank)
    S[yroot].parent = xroot;
    else
    {
        S[yroot].parent = xroot;
        S[xroot].rank++;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int V = A;
    int E = B.size();
    sort(B.begin(), B.end() ,func);
    //subset *S = new vector<subset>[A+1];
    vector<subset> S(A+1);
    for(int i=0 ; i<=A ; i++){
        S[i].parent = i;
        S[i].rank = 0;
    }
    int e = 0;
    int i = 0;
    int sum = 0;
    while(e < V-1){
        int x = find(S,B[i][0]);
        int y = find(S,B[i][1]);
        if(x != y){
            sum += B[i][2];
            unio(S,x,y);
            e++;
        }
        i++;
    }
    return sum;
}
