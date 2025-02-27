#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *a, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i + 1) % M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *a, int N, int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (rand() % 100) / 100.0;
    }
}

void findRowSum(const double *a, double *b, int N, int M){
    for(int i = 0; i < N; i++){
        b[i] = 0;
        for(int j = 0; j < M; j++){
            b[i] += a[i* M+j];
        }
    }
}

void findColSum(const double *a, double *b, int N, int M){
    for(int j = 0; j < M; j++){
        b[j] = 0;
        for(int i = 0; i < N; i++){
            b[j] += a[i * M + j];
        }
    }
}

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}