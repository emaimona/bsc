

function fibo($n) {
    if ($n -eq 0 -or $n -eq 1) {
        return 1
    }

    return $(fibo($n-1)) + $(fibo($n-2))
}

if ($args.count -ne 1) {
    $fib = read-host "N="
} else {
    $fib = $args[0]
}

$arr = @()
for ($i=0; $i -le $fib; $i++) {
    $arr += fibo($i)
}

write-host $arr