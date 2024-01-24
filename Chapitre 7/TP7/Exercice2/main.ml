(* Exercice 2 *)

let miroir n = 
  let rec nb_to_list n = 
    match n with
    | 0 -> []
    | _ -> (n mod 10)::nb_to_list (n/10) 
  in
  let rec compteur l c = 
    match l with
    | [] -> c
    | t::s -> compteur s (10*c+t)
  in compteur (nb_to_list n) 0
;;
      