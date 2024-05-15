let maxcarre2 a =
  let m1 = Array.length a in
  let m2 = Array.length a .(0) in
  let c Array.make_matrix m1 m2 0 in
  let i1 = ref 0 in
  let i2 = ref 0 in
  for i = 0 to m1 - 1 do
    for j = 0 to m2 - 1 do
    if i = 0 || j = 0 || a.(i).(j) = 0 then
    c.(i).(j) <- a.(i).(j) 
    else 
      begin
        c.(i)
        (*pas fini*)