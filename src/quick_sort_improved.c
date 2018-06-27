#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
	if (n<=1) return;
	int l, r, i, j, pivot;
	l = 0;
	pivot = A[0];
	for(i = j = 1;i < n;i++){
		if(A[i] <= pivot){
		int z = A[j];
		A[j] = A[i];
		A[i] = z;
		j++;
		}
	}
	l = j;
	int x = A[l-1];
	A[l-1] = A[0];
	A[0] = x;
	for(i = n-1,r = n; 0 < i; i--){
  	if(A[i] > pivot){
  		r--;
  		int y = A[r];
  		A[r] = A[i];
  		A[i] = y;
  	}
  }
  j = r-1;
	quick_sort(A,l-1);
	quick_sort(A+l,n-l);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
