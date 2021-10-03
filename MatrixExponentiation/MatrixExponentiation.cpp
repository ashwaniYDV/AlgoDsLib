#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

struct Matrix{
	vector<vector<int> > a;
	int dim;
	//Make a zero matrix by default, pass 1 for identity matrix
	Matrix() {}
	Matrix(int n,bool identity = 0){
		dim = n;
		a = vector<vector<int> > (n,vector<int>(n));
		if(identity)
			for(int i=0;i<n;++i)
				a[i][i] = 1;
	}
	Matrix operator*(const Matrix& mat){
		assert(dim == mat.dim);
		Matrix res(dim);
		for(int i=0;i<dim;++i)
			for(int j=0;j<dim;++j)
				for(int k=0;k<dim;++k)
					res.a[i][j] = (res.a[i][j]+(a[i][k]*mat.a[k][j]));
		return res;
	}
};

Matrix expMat(Matrix mat,int p){
	Matrix res(mat.dim,1);
	while(p){
		if(p&1)
			res = res*mat;
		mat = mat*mat;
		p>>=1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	int n = 2;
	//Input the nxn matrix
	Matrix a(n,1);
	Matrix b(n+1,1);
	a.a[0][1] = 2;
	//Calculate Mat expo.
	Matrix res = a*b;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cout<<res.a[i][j]<<" \n"[j==n-1];
	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}
