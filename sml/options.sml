
fun bad_max (xs : int list) =
    if null xs
    then 0
    else if null (tl xs)
    then hd xs
    else
        let val tl_ans = old_max(tl xs)
        in
            if hd xs > tl_ans
            then hd xs
            else tl_ans
        end
