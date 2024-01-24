(* Exercice 1 *)
 
let rec puissance a b =
  if b = 0 then 1
  else a*(puissance a (b-1)) 
;;

let b_to_bi l b i = 
  let rec transfo_aux l c k = 
    match l with 
    | [] -> if c = 0 then [] else [c]
    | t::s -> if k < i-1 then transfo_aux s (c + t*(puissance b k)) (k+1)
        else (c + t*(puissance b k))::transfo_aux s 0 0
  in transfo_aux l 0 0
;;

let racine_neme a n = 
  let c = ref 0 in
  while (puissance (!c) n) < a do
    c := !c + 1;
  done;
  !c ;;

let rec bi_to_b l bi i = 
  let b2 = racine_neme bi i in
  let rec transfo_aux l k =
    match l with
    | [] -> []
    | t::s -> if k < i-1 then (t mod b2)::transfo_aux (t/2::s) (k+1)
        else (t mod b2)::transfo_aux s 0
  in transfo_aux l 0
;;