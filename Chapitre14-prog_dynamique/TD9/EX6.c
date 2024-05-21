//bottom up

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **creer_matrice(int n, int m){
  int **p = malloc(sizeof(int*) *n);
  for (int i = 0; i<n;i++){
    p[i] = malloc(sizeof(int)*m);
  }
  return p;
}

void detruire_matrice(int **p,int n, int m){
  for (int i = 0; i<n;i++){
    free(p[i]);
  }
  free(p);
}

int coeff_binom(int k,int n){
  int **m = creer_matrice(n+1,k+1);
  for (int i = 0;i<=n;i++){
    for (int j = 0; j<=i && j<=k;j++){
      if (j==0 || j == i){
        m[i][j] = 0;
      }
      else{
        m[i][j] = m[i-1][j-1] + m[i-1][j];
      }
    }
  }
  int a = m[n][k];
  detruire_matrice(m,n+1,k+1);
  return a;

}
