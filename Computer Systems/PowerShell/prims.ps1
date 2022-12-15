
function is_prime($n) {
    for ($i=2; $i -lt $n; $i++) {
        if ($n % $i -eq 0) {
            return $false
        }
        
    }
    return $true
}

if ($args.count -ne 1) {
    write-host "Badd"
} else {
    $res = is_prime($args[0])
    write-host $res
        
}