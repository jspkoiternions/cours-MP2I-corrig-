# Méthode : Top-down

On a déjà vu fibo naive
```ocaml
let rec fibo_naf n =
  if n <= 1 then n 
  else fibo_naif (n-1) + fibo_naif (n-2) ;;
```
voici comment faire du top_down

fonction (e, structure )
Si e = cas de base : 
  structure (e) <- sortie attendue pour e
Sinon, si le résultat de e n'est pas stocké dans le structure :
  - appels résursifs fonction ($$e\_{i}$$, structure) pour calculer la sortie attendue pour e
  - structure (e) <- sortie attendue pour e
renvoyer structure(e)

---------------------------------------------------------
fonction :
- prend en entrée un argument et une structure mutable
- renvoie la solution attendue ET la stocke dans le structure  pour être réutilisée dans les appels récursifs

### Exemples :
1)
```ocaml
let rec fibo_top_down_aux n t = 
  (if n <= 1 then t.(n) <- n 
  else if 
  if t.(n) = 0 then 
    let a = fibo_top_down_aux (n-1) t in
    let b = fibo_top_down_aux (n-2) t in
    t.(n) <- a+b);
    t.(n);;

let fibo_top_down n = fibo_top_down_aux n (Array.make(n+1) 0);;
```

on appel cela la mémoïsation le fait de se rappeler des résultats déja calculés

2)
Plus longue sous séquence commune
```ocaml
let rec plssc s1 s2 l1 l2 mat_longueur =
if l1 = 0 || l2 = 0 
  then (mat_longueur.(l1).(l2) <- 0)
else 
    (if mat_longueur.(l1).(l2) = -1 then 
  if s1 .[l1-1] = s2.[l2-1] then
  mat_longueur.(l1).(l2) <- 1 + plssc s1 s2 (l1-1) (l2-1) mat_longueur
  else let longueur1 = plssc s1 s2 (l1-1) (l2) mat_longueur in
    let longueur1 = plssc s1 s2 l1 (l2-1) mat_longueur in
    (mat_longueur.(l1).(l2) <- max longueur1 longueur2));
  mat_longueur.(l1).(l2) ;;
```
