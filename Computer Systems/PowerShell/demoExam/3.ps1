
if ($args.count -ne 1) {
    write-host "Exactly one arg is needed"
} else {

    if (test-path short.txt) {
        remove-item short.txt
    }

    if (test-path $args[0]) {
        $text = get-content $args[0]

        foreach ($row in $text) {
            if ($row.length -lt 5) {
                write-output $row >> short.txt
            }
        }
    } else {
        write-host "file not found"
    }
}

