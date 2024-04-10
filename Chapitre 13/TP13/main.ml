type 'a formule = Var of 'a
                | Vrai
                | Faux
                | Et of 'a formule * 'a formule
                | Ou of 'a formule * 'a formule
                | Neg of 'a formule ;;

let rec insertion_sans_doublon e l =
  match l with
  | [] -> [e]
  | t::s -> if t = e then l else t::(insertion_sans_doublon e s) ;;

let rec fusion_sans_doublon l1 l2  =
  match l1 with
  | [] -> l2
  | t::s -> insertion_sans_doublon t (fusion_sans_doublon s l2) ;;

let rec variables f = 
  match f with 
  | Vrai | Faux -> []
  | Var(a) -> [a]
  | Neg(f2) -> variables f2 
  | Et(f1,f2) -> fusion_sans_doublon (variables f1) (variables f2)
  | Ou(f1,f2) -> fusion_sans_doublon (variables f1) (variables f2);;

let f = Ou(Var("a"), Et(Var("c"),Var("b")));;

let rec list_val l =
  match l with 
  | [] -> [[]]
  | t::s -> let rec insertion_sous_liste e l =
              match l with
              | [] -> [] 
              | t::s -> (e::t)::(insertion_sous_liste e s) 
      in (insertion_sous_liste (t,false) (list_val s)) @ (insertion_sous_liste (t,true) (list_val s));; 

(*exercice 3*)

let rec valuation_liste a l =
  match l with
  | [] -> failwith "pas de valutation"
  | (a1,b) :: s -> if a1 = a then b else valuation_liste a s;;

let rec eval_val_l_v1 f v =
  match f with
  | Faux -> false
  | Vrai -> true
  | Var(a) -> valuation_liste a v
  | Neg(f1) -> not(eval_val_l_v1 f1 v)
  | Et(f1,f2) -> (eval_val_l_v1 f1 v) || (eval_val_l_v1 f2 v)
  | Ou(f1,f2) -> (eval_val_l_v1 f1 v) && (eval_val_l_v1 f2 v);;

(*let f0 = Ou(Et(Neg(Var("a"),Var("b")), Var("c")), Et(Ou(Neg(Var("b"),Var("c") )), Var("a")));;*)

let rec subsitution f x b =
  match f with
  | Vrai -> Vrai 
  | Faux -> Faux
  | Var(a) -> if a = x then if b then Vrai else Faux 
    else Var(a) 
  | Neg(f1) -> Neg(subsitution f1 x b)
  | Ou(f1,f2) -> Ou(subsitution f1 x b, subsitution f2 x b)
  | Et(f1,f2) -> Et(subsitution f1 x b, subsitution f2 x b);;

let rec simplif_quine f =
  match f with
  | Et(Faux,f1) | Et(f1,Faux) -> Faux
  | Et(Vrai,f1) | Et(f1,Vrai) -> f1
  | Ou(Faux,f1) | Ou(f1,Faux) -> f1
  | Ou(Vrai,f1) | Ou(f1,Vrai) -> Vrai
  | Neg(Vrai) -> Faux
  | Neg(Vrai) -> Vrai
  | Et(f1,f2) -> if(simplif_quine f1 = f1 && simplif_quine f2 = f2) then Et(f1,f2) else simplif_quine (Et (simplif_quine f1), (simplif_quine f2))
  | Ou(f1,f2) -> if(simplif_quine f1 = f1 && simplif_quine f2 = f2) then Ou(f1,f2) else simplif_quine (Ou (simplif_quine f1), (simplif_quine f2))
  | Neg(f1) ->  if(simplif_quine f1 = f1) then Neg(f1) else simplif_quine (Neg (simplif_quine f1)) ;;

type 'a arbre_quine =
| Valide
| Invalide
| Noeud of 'a * 'a arbre_quine * 'a arbre_quine
;;

let arbre f =
  let f_bis = simplif_quine f in
  match f_bis with
  | Vrai -> Valide
  | Faux -> Invalide
  | _ -> let var = variables f_bis in
        let (t::s) = var in
        let f1 = simplif_quine (subsitution f t true) in
        let f2 = simplif_quine (subsitution f t false) in
        Noeud(t,arbre f1,arbre f2) ;;
        
type 'a lit = V of 'a  | N of 'a ;;

type 'a cnf 'a lit list list;;

 























