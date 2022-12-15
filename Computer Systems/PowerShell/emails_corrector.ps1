
if ($args.count -ne 1) {
    [string]$path = read-host "Filename: "
} else {
    $path = $args[0]
}

if (test-path $path) {
    if (test-path result.txt) {
        remove-item result.txt
    }

    $text = get-content $path

    foreach ($row in $text) {
        $row = $row.replace(" at ", "@").replace(" dot ", ".")
        write-output $row >> result.txt
        write-output $row
    }
} else {
    write-host "File not found!"
}