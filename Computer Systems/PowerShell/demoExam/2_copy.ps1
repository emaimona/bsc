
$n = $args[0] 

function is_prime($x) {
    $i = 2
    while ($x % $i -ne 0) {
        $i++;
    }
    return $i -eq $x
}

function write_divisors($x) {
    $arr = @()
    for ($i=1; $i -le $x; $i++) {
        if ($x % $i -eq 0) {
            $arr += $i
        }
    }

    return $arr
}

if (is_prime($n)) {
    write-host "$n is prime"
} else {
    write-host "$n is not primea and its divisors are: "
    $arr = write_divisors($n)
    write-host $arr
}