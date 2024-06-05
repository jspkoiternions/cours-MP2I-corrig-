type graphe = int list array ;;

let parcours_profondeur_rec g in
let est_visite = .make n false in

let rec visite s1 = 
  if not(est_visite.(s1)) then
  begin
    Printf.printf "sommet parcouru : %d \n" s1;
    est_visite <- true;

    let rec visite_voisin l =
      match l with
      | [] -> ()
      | t::s -> visite t; visite_voisin s;

    in visite_voisin (g.(s1));
  end
in visite s;;

let g:graph = [|[1;2;6];[0;3];[0;4];[1;5];[2;5];[3;4;6];[0;5]|];;