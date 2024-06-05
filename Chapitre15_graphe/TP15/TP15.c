#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

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
    l_sommet **tab;
};
typedef struct liste_graphe liste_graphe;

liste_graphe *creer_liste_graphe(int n){
    liste_graphe *l = malloc(sizeof(liste_graphe));
    l->taille = n;
    l_sommet *tab1 = malloc(sizeof(l_sommet*)*n);
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

mat_graphe* creer_mat_graphe (int n){
    bool **m1 = creer_matrice(n,n);
    for (int i = 0 ; i<n; i++){
        for(int j = 0; j < n; j++){
                m1[i][j] = false;
        }
    }
    mat_graphe *m = malloc(sizeof(mat_graphe));
    m->taille = n;
    m->mat = m1;
    return m;
}

void detruire_matrice(bool **m1, int n){
    for (int i = 0;i<n;i++){
        free(m1[i]);
    }
}

void supprimer_mat_graphe(*mat_graphe m1){
    detruire_matrice(m1->mat,m1->taille);
    free(m);
}

void ajout_arete_go (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    bool **m1 = m->mat;
    m1[s1][s2] = true;
}

void ajout_arete_gno (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    bool **m1 = m->mat;
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
/*
liste_graphe *mat_to_list(mat_graphe *m){
    int n = m->taille;
    bool**m0 = m->mat;

    liste_graphe *l

}*/

mat_graphe *list_to_mat(liste_graphe *l){
    int n = l->taille;
    l_sommet **t = l->tab;
    mat_graphe *m1 = creer_mat_graphe(n);
    for(int i = 0;i<n;i++){
        l_sommet *ls = t[i];
        while (ls != NULL){
            int j = ls->valeur;
            m1->mat[i][j] = true;
            ls = ls-> next;
        }
    }
    return m1;
} 

//q8
bool est_gno(mat_graphe* m){
    int n = m->taille;
    int m0 = m->mat;
    for(int i = 0;i<n;i++){
        for (int j = 0;j<i;j++){
            if(m0[i][j] != m0[i][j]){
                return false;
            }
        }
    }
    return true;
}


liste_graphe *list_to_mat()


int nb_arete_go_list(liste_graphe *l0){
    int n = l0->taille;
    int c = 0;
    l_sommet* t = l0->l;
    for(int i = 0; i<n;i++){
        l_sommet* l1 = t+i;
        while(l1 != NULL){
            c++;
            l1 = l1->next;
        }
    }
}

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
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
    l_sommet **tab;
};
typedef struct liste_graphe liste_graphe;

liste_graphe *creer_liste_graphe(int n){
    liste_graphe *l = malloc(sizeof(liste_graphe));
    l->taille = n;
    l_sommet *tab1 = malloc(sizeof(l_sommet*)*n);
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

mat_graphe* creer_mat_graphe (int n){
    bool **m1 = creer_matrice(n,n);
    for (int i = 0 ; i<n; i++){
        for(int j = 0; j < n; j++){
                m1[i][j] = false;
        }
    }
    mat_graphe *m = malloc(sizeof(mat_graphe));
    m->taille = n;
    m->mat = m1;
    return m;
}

void detruire_matrice(bool **m1, int n){
    for (int i = 0;i<n;i++){
        free(m1[i]);
    }
}

void supprimer_mat_graphe(*mat_graphe m1){
    detruire_matrice(m1->mat,m1->taille);
    free(m);
}

void ajout_arete_go (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    bool **m1 = m->mat;
    m1[s1][s2] = true;
}

void ajout_arete_gno (mat_graphe *m, int s1, int s2){
    int n = m->taille ;
    assert(s1>=0 && s1<n && s2>= 0 && s2<n);
    bool **m1 = m->mat;
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
/*
liste_graphe *mat_to_list(mat_graphe *m){
    int n = m->taille;
    bool**m0 = m->mat;

    liste_graphe *l

}*/

mat_graphe *list_to_mat(liste_graphe *l){
    int n = l->taille;
    l_sommet **t = l->tab;
    mat_graphe *m1 = creer_mat_graphe(n);
    for(int i = 0;i<n;i++){
        l_sommet *ls = t[i];
        while (ls != NULL){
            int j = ls->valeur;
            m1->mat[i][j] = true;
            ls = ls-> next;
        }
    }
    return m1;
} 

//q8
bool est_gno(mat_graphe* m){
    int n = m->taille;
    int m0 = m->mat;
    for(int i = 0;i<n;i++){
        for (int j = 0;j<i;j++){
            if(m0[i][j] != m0[i][j]){
                return false;
            }
        }
    }
    return true;
}


liste_graphe *list_to_mat()


int nb_arete_go_list(liste_graphe *l0){
    int n = l0->taille;
    int c = 0;
    l_sommet* t = l0->l;
    for(int i = 0; i<n;i++){
        l_sommet* l1 = t+i;
        while(l1 != NULL){
            c++;
            l1 = l1->next;
        }
    }
}

//partie 2 PILE
struct pile{
    liste *premier;
};
typedef struct pile pile;

bool isempty_pile(pile *p){
    return (p->premier == NULL);
}

void *ajout_pile(pile *p,int e){
    p->premier = ajout_liste(p->premier,e);
}

int dernier_elt_pile(pile *p){
    assert(!isempty_pile(p));
    liste *l1 = p->premier;
    int v = l1->valeur;
    return v;
}

int depiler(pile *p){
    assert(!isempty_pile(p));
    liste *l1 = p->premier;
    int v = l1->valeur;
    p->premier = l1->next;
    free(l1);
    return v;
}

pile *creer_pile(){
    pile *p = malloc(sizeof(pile));
    p->premier=NULL;
    return p;
}

void parcours_profondeur(liste_graphe *l, int s){
    //champ de *l
    int n = l->taille;
    l_sommet **t = l->tab;

    //initi de la pile et du tableau de visite
    pile *p = creer_pile();
    bool *est_visite = malloc(sizeof(bool)*n);
    for (int i = 0;i<n;i++){
        est_visite[i] = false;
    }
    ajout_pile(p,s);

    while(!isempty_pile(p)){
        int s1 = depiler(p);
        if(!est_visite[s1]){
            printf("sommet %d parcouru \n",s1);
            est_visite[s1]=true;

            l_sommet *ls = t[s1];

            while(ls!= NULL){
                int v = ls->valeur;
                if(!est_visite[v]){
                    ajout_pile(p,v);
                }
                ls = ls->next;
            }
        }
    }
    free(est_visite);
}

void visite(G,s,t){
    if (!t[s]){
        printf("")
    }
}

int main(){
    liste_graphe *l creer_liste_graphe(7);
    l_sommet *l0 = NULL;
    l0 = ajout_l_sommet(l0,1);
    l0 = ajout_l_sommet(l0,2);
    l0 = ajout_l_sommet(l0,6);
    l->tab[0] = l0; 
}


int main(){

    return 0;
}






int main(){

    return 0;
}



