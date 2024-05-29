#include <stdbool.h>


typedef struct lst_ch
{ int value ; struct lst_ch *next;}
list;

typedef struct type mat_graph
{
  int taille;
  bool **mat;
} mat_graph

typedef struct liste_graphe
{
  int taille;
  l_sommet *list;
} liste_graphe;

bool **creer_matrice(int n,int m){
    bool *p = malloc(sizeof(bool*)*n);
    for (int i = 0;i<n; i++){
        p[i] = malloc(sizeof(bool)*m);
    }
}

mat_graph* creer_mat_graphe (int n){
    bool **m1 = creer_matrice(n,n);
    for (int i = 0 ; i<n; i++){
        for(int j = 0; j < n; j++){
                m1[i][j] = false;
        }
    }
    mat_graph *m = malloc(sizeof(mat_graph));
    m->taille = n;
    m->mat = m1;
    return m;
}

void detruire_matrice(bool **m1, int n){
    for (int i = 0;i<n;i++){
        free(m1[i]);
    }
}

void supprimer_mat_graphe(*mat_graph m1){
    detruire_matrice(m1->mat,m1->taille);
    free(m);
}

