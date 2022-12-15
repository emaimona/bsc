
if ($args.count -ne 1) {
    write-host "Exactly one arg is needed"
} else {

    if (test-path $args[0]) {
        $text = get-content $args[0]

        foreach ($row in $text) {
            $words = $row.split()
            write-host $words.length
        }
    } else {
        write-host "file not found"
    }
}

