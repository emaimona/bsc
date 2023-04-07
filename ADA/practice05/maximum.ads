
generic 
    type T is private;
    with function "<" (A, B: T) return Boolean;
function Maximum(A, B: T) return Boolean;
