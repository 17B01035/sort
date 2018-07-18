#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int x, m, l, r, i, j, pivot;
  l = 0;
  x = 0;

// 先頭の要素をピボットとする
  pivot = A[0];
  for(i = j = 1; i < n; i++){
    if(A[i] < pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
    }
  }
  l = j;
  for(i = n-1,r = n; 0 < i; i--){
  	if(A[i] > pivot){
  		r--;
  		int y = A[r];
  		A[r] = A[i];
  		A[i] = y;
  	}
  }
  j = r-1;
  m = A[1];
  for(i = 2; i < l; i++){
  	if(m == A[i]) x++;
  }
  if(l == k+1+x) return pivot;
  else if(l < k+1+x) return quick_select(A+r, n-r, k+x-l);
  else return quick_select(A+1, l-1, k);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
