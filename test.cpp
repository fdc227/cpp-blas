#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> cross_product(const vector<T>& A, const vector<T>& B)
{
    vector <T> C(3);
    C[0] = A[1]*B[2]-A[2]*B[1];
    C[1] = -A[0]*B[2]+A[2]*B[0];
    C[2] = A[0]*B[1]-A[1]*B[0];
    return C;
}

template<typename T>
T dot_product(const vector<T>& A, const vector<T>& B)
{
    int n = B.size();
    T sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += A[i]*B[i];
    }
    return sum;
}

template<typename T>
void printvec(vector<T>& A)
{
    cout<<A[0]<<'\n'<<A[1]<<'\n'<<A[2]<<endl;
}

template<typename T>
void printmat(vector<vector<T>>& M)
{
    int n = M.size();
    int m = M[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==n-1){cout<<M[i][j]<<'\n';}
            else{cout<<M[i][j]<<'\t';}
        }
    }
}

template<typename T>
vector<T> matvec(vector<vector<T>>M, vector<T>V)
{
    int n = V.size();
    vector<T> P(n);
    for(int i=0; i<n; i++)
    {
        P[i] = dot_product<T>(M[i], V);
    }
    return P;
}

//return y = a*x
template<typename T>
void ax(T a, vector<T>& x)
{
    int n = x.size();
    vector<T> y(n);
    for(int i=0;i<n;i++)
    {
        y[i] = a * x[i];
    }
}

//return y = a*x + y 
template<typename T>
void axpy(T a, vector<T>& x, vector<T>& y)
{
    int n = x.size();
    for(int i=0;i<n;i++)
    {
        y[i] += y[i] + a*x[i];
    }
}

//return y = M*x + y
template<typename T>
void mxpy(vector<vector<T>>& M, vector<T>& x, vector<T>& y)
{
    int n = x.size();
    for(int i=0;i<n;i++)
    {
        axpy(x[i], M[i], y);
    }
}

//return C = A*B + C, where A(m*k), B(k*n), C(m*n)
template<typename T>
void gemm(vector<vector<T>>& A, vector<vector<T>>& B, vector<vector<T>>& C)
{
    int n = C.size();
    for(int i=0;i<n;i++)
    {
        mxpy(A, B[i], C[i]);
    }
}

int main(void)
{
    vector<float> A({1,2,3});
    vector<float> B({4,5,6});
    vector<float> D({1,2,3});
    // cout<<A[0]<<endl;
    // print_vector<float>(A);
    // vector<float> C(3);
    // C = cross_product<float>(A, B);
    // print_vector<float>(C);
    // print_vector<float>(D);
    // cout<<dot_product(A,B)<<endl;
    vector<vector<float>> M({{1,2,3},{4,5,6},{7,8,9}});
    vector<vector<float>> N({{1,2,3},{4,5,6},{7,8,9}});
    vector<vector<float>> C({{0,0,0},{0,0,0},{0,0,0}});
    gemm(M, N, C);
    printmat(C);

    // print_vector<float>(M[0]);
    // vector<float> P(3);
    // P = matvec<float>(M, A);
    // print_vector<float>(P);

    // float sum = dot_product<float> (M[0],A);
    // cout<<sum<<endl;
    // cout<<M.size()<<endl;
    
    return 0;
}