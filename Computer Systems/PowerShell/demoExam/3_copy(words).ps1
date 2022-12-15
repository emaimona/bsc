
if ($args.count -ne 1) {
    write-host "Exactly one arg is needed"
} else {

    if (test-path short_words.txt) {
        remove-item short_words.txt
    }

    if (test-path $args[0]) {
        $text = get-content $args[0]

        foreach ($row in $text) {
            $words = $row.split()
            foreach ($word in $words) { 
                if ($word.length -lt 5) {
                    Add-Content short_words.txt  $word
                }
            }
        }
    } else {
        write-host "file not found"
    }
}

