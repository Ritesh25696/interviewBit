Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

***********************************************************************************************************************************************************

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int, int> > > hp;
	set<pair<int, int> > S;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
	S.insert(make_pair(n-1, n-1));

	vector<int> ans;
	int k=n;
	while(k--){
		pair<int, pair<int, int> > top = hp.top();
		hp.pop();
		ans.push_back(top.first);
		int L = top.second.first;
		int R = top.second.second;
		
		if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() ){
			hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
			S.insert(make_pair(L,R-1));
		}
		if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end()){
			hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
			S.insert(make_pair(L-1, R));
		}
	}
	return ans;
}
