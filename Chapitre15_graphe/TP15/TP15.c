#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

struct mat_graphe{
    int taille;
    bool **mat;
};
typedef struct mat_graphe mat_graphe;

struct l_sommet{
    int valeur;
    struct l_sommet *next;
};
typedef struct l_sommet l_sommet;

l_sommet *ajout_l_sommet(l_sommet *l,int e){
    l_sommet *l1 = malloc(sizeof(l_sommet));
    l1->valeur = e;
    l1->next = l;
    return l1;
}

struct liste_graphe{
    int taille;
    l_sommet *tab;
};
typedef struct liste_graphe liste_graphe;

liste_graphe *creer_liste_graphe(int n){
    liste_graphe *l = malloc(sizeof(liste_graphe));
    l->taille = n;
    l_sommet *tab1 = malloc(sizeof(l_sommet)*n);
    l->tab = tab1;
    return l;
}

struct pile{
    int valeur;
    struct pile* next;
};
typedef struct pile pile;

bool isempty_pile(pile *p){
    return (p == NULL);
}

pile *ajout_pile(pile *p,int e){
    pile *p1 = malloc(sizeof(pile));
    p1->valeur = e;
    p1->next = p;
    return p1;
}

pile *depiler(pile *p){
    assert(!isempty_pile(p));
    pile *p1 = p->next;
    free(p);
    p = p1;
    return p;
}

pile *creer_pile(){
    pile *p = NULL;
    return p;
}

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


void ajout_arete_go (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    boot **m1 = m->mat;
    m1[s1][s2] = true;
}

void ajout_arete_gno (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    boot **m1 = m->mat;
    m1[s1][s2] = true;
    m1[s2][s1] = true;
}

int nb_arete_go (mat_graphe *m){
    int n = m->taille;
    bool**m1 = m->mat;
    int compteur = 0;
    for (int i = 0 ; i<n; i++){
        for(int j = 0;j<n;j++){
            if (m1[i][j]){
                compteur++;
            }
        }
    }
    return compteur;
}

int nb_arete

int main(){

    return 0;
}



