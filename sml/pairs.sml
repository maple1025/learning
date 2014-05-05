
fun swap (pr : int*bool) =
    (#2 pr, #1 pr)

fun sum_two_paris (pr1 : int*int, pr2 : int*int) =
    (#1 pr1) + (#2 pr2) + (#1 pr2) + (#2 pr1)

fun div_mod (x: int, y: int) = (* note: returning a pair a real pain in Java *)
    (x div y, x mod y)

    
fun reverse l =
    let fun rev(nil, y) = y
          | rev(hd::tl, y) = rev(tl, hd::y)
    in
        rev(l, nil)
    end


    
