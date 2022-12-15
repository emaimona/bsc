if ($args.count -eq 3) {
    $dat = $args
} else {
    $dat = @()

    foreach ($i in $input) {
        $dat += $i
    }
}

if ($dat.count -ne 3) {
    write-host "Error"
} else {
    for ($i=1; $i -le $dat[2]; $i++) {
        echo $dat[0]
        $dat[0] += $dat[1]
    }
}