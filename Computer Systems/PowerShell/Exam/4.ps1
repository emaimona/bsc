
if ($args.count -ne 2) {
    write-host "Exactly one arg is needed"
} else {
    if (test-path $args[0]) {
        $text = Get-Content $args[0]
        $n = [int] $args[1]

        foreach ($row in $text) {
            $words = $row.split()
            if ($words.length -gt $n) {
                write-host $row   
            }
        }
    } else {
        write-host "File not found!"
    }
}
