if ($args.length -ne 1) {
    write-host "We need just one argument"
} else {

    $f = 1
    $n = $args[0]

    for ($i=1; $i -le $n; $i++) {
        $f *= $i;
    }
    write-host $f
}