
(* This is a comment. This is our first porgram. *)

val x = 34;
    (* static environment : x : int *)
    (* dynamic environment: x --> 34 *)
    
val y = 17;

val z = (x + y) + (y + 2)

val abs_of_z = if z < 0 then 0 - z else z;
