let rec ent n =
  match n/10 with
  |0 -> (n)::[] 
  |_ -> (n mod 10)::(ent (n/10));;