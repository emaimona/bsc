param([int]$n)

function is_prime($x) {
    $i = 2
    while ($x % $i -ne 0) {
        $i++;
    }
    return $i -eq $x
}

function write_divisors_1($x) {
    for ($i=1; $i -le $x; $i++) {
        if ($x % $i -eq 0) {
            write-host $i
        }
    }
}


if (is_prime($n)) {
    write-host "$n is prime"
} else {
    write-host "$n is not primea and its divisors are: "
    write_divisors_1($n)
}