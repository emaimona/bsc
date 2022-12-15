param([string]$filename)

if (Test-path $filename) {
    $content = get-content $filename

    if (test-path even.txt) {
        remove-item even.txt
    }
    if (test-path odd.txt) {
        remove-item odd.txt
    }
    $i = 1
    foreach ($row in $content) {
        if ($i % 2 -ne 0) {
            write-output $row >> odd.txt
        } else {
            write-output $row >> even.txt
        }
        $i++
    }
} else {
    write-host "File not found"
}
