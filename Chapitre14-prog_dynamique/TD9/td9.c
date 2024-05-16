#include <stdio.h>
#include <stdlib.h>

struct result{int *t;int size;};
typedef struct result result;

result rendu_monnaie_glouton(int n, int p[n], int x){
  //en supposant le tableau p 
  int *t = malloc(sizeof(struct result));
  int monnaie = x;
  int i = n-1;
  while (monnaie > 0){
    if (monnaie>= p[i]){
      monnaie -= p[i];
      t[i]++;
    }
    else {
      i--;
    }
  }
  result res = {t, n};
  return res;
}

int **creer_matrice(int n, int m){
  int **p = malloc(sizeof(int*)*n);
  for (int i = 0; i<n i ++){
    p[i] = malloc(sizeof(int)*m);
  }
  return p ;
}

void detruire_matrice(int **p,int n, int m){
  for(int i = 0; i<n;i++){
    free(p[i]);
  }
  free(p);
}

//on redef ici result ne fait plus la même longueur que celui de nombre de pièce 
)
result monnaie_monnaie_dynamique(int n, int p[n], int x){
  int **s = creer_matrice(n,x+1);
  for (int i = 0;i < n; i++){
    s[i][0] = 0;
  }
  for (int k = 1; k<=x;k++){
    if(k-p[0] >= 0){
      s[0][k]=1;
    }
    else{
      s[0][k] = INT_MAX;
    }
  }
}

int main(){

  int v = 6;
  int p[] = {1,3,4};
  result res = rendu_monnaie_glouton(3,p,v);
  for (int i = 0; i < res.size-1; i++){
    printf("%d",res.t[i]);
  }
  return 0;
}

