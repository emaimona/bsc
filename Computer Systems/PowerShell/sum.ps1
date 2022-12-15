
if ($args.count -ne 2) {
    $content = @()
    $content += $input

    write-host $content[0] + $content[1] = $($content[0] + $content[1])
} else {
    write-host $args[0] + $args[1] = $($args[0] + $args[1])
    write-host "I love Emanuele".Substring(7, 3)
}