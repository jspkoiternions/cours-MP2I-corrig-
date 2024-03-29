(*Exercice 3*)
(*
a -> taille k
b -> taille k : 
 a+b -> taille k+1
 *) 
 
let a = [|true;false;true;true|];;

let b = [|true;false;false;true|];; 
  

let somme_trois_booleens b1 b2 b3 =
  let b1_int = if b1 then 1 else 0 in 
  let b2_int = if b2 then 1 else 0 in 
  let b3_int = if b3 then 1 else 0 in
  (b1_int+b2_int+b3_int) mod 2 = 1;;

let ret_trois_booleens b1 b2 b3 =
  let b1_int = if b1 then 1 else 0 in
  let b2_int = if b2 then 1 else 0 in
  let b3_int = if b3 then 1 else 0 in
  (b1_int + b2_int + b3_int) > 1;;

  
let somme t1 t2 =
  let n = Array.length t1 in
  let t = Array.make (n+1) false in
  let ret = ref false in
  for k = 0 to (n-1) do
    t.(k) <- somme_trois_booleens (t1.(k)) (t2.(k)) (!ret);
    ret := ret_trois_booleens t1.(k) t2.(k) (!ret);
  done;
  t.(n) <- !ret;
  t;;



let somme_liste l1 l2 =
  let rec somme_aux l1 l2 ret =
    match (l1,l2) with 
    | ([],[]) -> [ret]
    | ([],_) -> l1
    | (_,[]) -> l2
    | (t1::s1,t2::s2) -> let ret2 = ret_trois_booleens t1 t2 ret in
        (somme_trois_booleens t1 t2 ret)::(somme_aux s1 s2 ret2)
  in somme_aux l1 l2 false ;;

