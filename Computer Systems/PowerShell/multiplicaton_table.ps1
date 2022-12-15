

for ($i=1; $i -le 10; $i++) {
    for ($j=1; $j -le 10; $j++) {
        write-host $i * $j = $($i * $j)
    }
    write-host
}