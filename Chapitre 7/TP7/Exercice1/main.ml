(*TP7 Exercice 1*)

let rec puissance a n = 
  match n with
  |0 -> 1
  | _ -> a*(puissance a (n-1)) ;;

let base_puissance_petit_boutisme l b i = 
  let rec base_aux l b i v i1 = 
    match (l,(i-i1)) with
    |([],_) -> if v > 0 then [v] else []
    |(t::s,0) -> v::(base_aux s b i t 1)
    |(t::s,k) -> base_aux s b i (v+t*(puissance b i1)) (i1+1) 
  in base_aux l b i 0 0 ;;