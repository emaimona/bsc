if ($args.count -eq 1) {
    if (test-path $args[0]) {
        $content = @()
        $content += get-content $args[0]
        foreach ($dat in $content) {
            if ($dat -match "^[0-9a-z]{6}$") {
                write-host "$dat is a neptun code"
            } else {
                write-host "$dat is not :("
            }
        }
    } else {
        write-host "Not a file name"
    }

} else {
    write-host "File name needed"
}