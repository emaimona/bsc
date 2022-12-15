param([string]$path)


function is_pali($word) {
    $i = 0
    $j = $word.length - 1

    while ($i -lt $j) {
        if ($word[$i] -ne $word[$j]) {
            break
        }

        $i++
        $j--
    }

    return $i -ge $j
}


if (test-path $path) {
    if (test-path same.txt) {
        remove-item same.txt
    }

    $text = get-content $path

    foreach ($row in $text) {
        if (is_pali($row)) {
            write-output $row >> same.txt
        }
    }
    
} else {
    write-host "Path not found"
}