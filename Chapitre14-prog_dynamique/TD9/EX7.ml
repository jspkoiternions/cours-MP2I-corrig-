let rec valide (i,j) l=
  match l with
  | [] -> true
  | (i1,j1)::s -> i <> i1 && j <> j1 && abs(i-i1) <> abs(j-j1) && (valide (i,j) s);;