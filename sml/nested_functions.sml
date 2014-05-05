fun countup_from (x : int) =
    let
        fun count (from : int) =
            if from = x
            then x :: []
            else from :: count(from + 1)
    in
        count(1)
    end

fun bad_max (xs : int list) =
    if null xs
    then 0
    else if null (tl xs)
    then hd xs
    else if hd xs > bad_max(tl xs)
    then hd xs
    else bad_max(tl xs)

fun good_max (xs : int list) =
    if null xs
    then 0
    else if null (tl xs)
    then hd xs
    else
        let val tl_ans = good_max(tl xs)
        in
            if hd xs > tl_ans
            then hd xs
            else tl_ans
        end

fun max1 (xs : int list) =
    if null xs
    then NONE
    else
        let val tl_ans = max1(tl xs)
        in if isSome tl_ans andalso valOf tl_ans > hd xs
           then tl_ans
           else SOME (hd xs)
        end
