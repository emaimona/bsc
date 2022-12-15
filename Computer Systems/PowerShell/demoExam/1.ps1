
if ($args.count -ne 2) {
    write-host "Two elements are needed"
} else {
    $base = $args[0]
    $count = $args[1]

    for ($i=0; $i -le $count; $i++) {
        write-host $([math]::Pow($base, $i)) " " -NoNewline
    }

    write-host ""
}