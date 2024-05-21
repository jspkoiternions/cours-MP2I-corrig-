(*binomiaux en top down*)

let rec coeff_binom_aux k n t =
  if t.(k).(n) = 0 then 
    begin
      if k = 0 || k = n then
        t.(k).(n) <- 1
      else 
        let a = coeff_binom_aux (k-1) (n-1) t in
        let b = coeff_binom_aux k (n-1) t in
        t.(k).(n) <- a+b ;
    end;
  t.(k).(n);;

let coeff_binom k n =
  coeff_binom_aux k n (Array.make_matrix (k+1) (n+1) 0);