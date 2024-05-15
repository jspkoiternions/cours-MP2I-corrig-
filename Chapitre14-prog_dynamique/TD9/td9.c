#include <stdio.h>
#include <stdlib.h>

struct result{int *t;int size;};
typedef struct result result;

result rendu_monnaie_glouton(int n, int p[n], int x);

int main(){

  int v = 6;
  int p[] = {1,3,4};
  result res = rendu_monnaie_glouton(3,p,v);
  for (int i = 0; i < res.size-1; i++){
    printf("%d",res.t[i]);
  }
  return 0;
}

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
