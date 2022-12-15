
if ($args.count -ne 1) {
    write-host "Filename is needed!"
} else {
    if (test-path $args[0]) {
        $text = @()
        $text += Get-Content $args[0]

        $sum = 0
        foreach ($row in $text) {
            $row = [int] $row
            if ($row % 2 -eq 0) {
                $sum += $row
            }
        }
        write-host $sum
    } else {
        write-host "File not found!"
    }
}