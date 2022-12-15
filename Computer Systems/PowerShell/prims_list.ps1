param([int]$lower, [int]$upper)

function prim($n) {
    $i = 2;

    while (($i -le $n) -and ($n % -$i -ne 0)) {
        $i++;
    }

    return $i -eq $n
}

for ($i=$lower; $i -le $upper; $i++) {
    if (prim $i) {
        write-host $i
    }  
}