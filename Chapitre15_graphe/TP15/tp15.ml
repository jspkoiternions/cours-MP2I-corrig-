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


(*algo de floyd warshall*)

type mat_adj = float option array array ;;

let fw_bottom_up (m1:mat_adj) = 
  let n = Array.length m1 in
  let w = Array.make_matrix n n None in
  let w_copy = Array.make_matrix n n None in

  for k = 0 to n do
    if k = 0 then
      begin
        for i = 0 to (n-1) do
          for j = 0 to (n-1) do
            w.(i).(j) <- m1.(i).(j)
          done;
        done;
      end
    else 
      begin
        for i = 0 to (n-1) do
          for j = 0 to (n-1) do
            w_copy.(i).(j) <- m1.(i).(j)
          done;
        done; 
        for i = 0 to (n-1) do
          for j = 0 to (n-1) do
            let e1 = w_copy.(i).(k-1) and e2 = w_copy.(k-1).(j) in
            if e1 <> None && e2 <> None then
              begin
                let Some(b1) = e1 and Some(b2) = e2 in

                if w_copy.(i).(j) = None then
                  w.(i).(j) <- Some(b1+.b2) 
                else
                  let Some (b3) = w_copy.(i).(j)in
                  if (b3 > b1+.b2) then
                    w.(i).(j) <- Some(b1+.b2)
              end
          done;
        done;
      end
  done;
  w;;