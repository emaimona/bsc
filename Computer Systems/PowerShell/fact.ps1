param([int]$n)

$f=1

for ($i=1; $i -le $n; $i++) {
    $f*= $i;
}

write-host $f