let rec fibo_top_down_aux n t = 
  (if n <= 1 then t.(n) <- n 
  else if 
  if t.(n) = 0 then 
    let a = fibo_top_down_aux (n-1) t in
    let b = fibo_top_down_aux (n-2) t in
    t.(n) <- a+b);
    t.(n);;

let fibo_top_down n = fibo_top_down_aux n (Array.make(n+1) 0);;