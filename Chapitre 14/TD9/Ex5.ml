let min a b =
  if a < b then a 
  else b;;


let min_tab t =
  let l = Array.length t in
  let m = ref t.(0) in
  for i = 1 to l do
    m := min t.(i-1) t.(i);
  done;
  !m;;

let rec rendu n a = 
  let k = Array.length a in
  let rec aux n k a =
    if n = 0 then 0
    else if a.(k) < n then aux n (k-1) a 
    else min_tab a + 1 in aux n k a;;



let t = [|1;2;5;10;20;50;100;200;500|]

