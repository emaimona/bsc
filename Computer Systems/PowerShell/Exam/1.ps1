
if ($args.count -ne 2) {
    $a = [int] (read-host "a=")
    $b = [int] (read-host "b=")
} else {
    $a = [int] $args[0]
    $b = [int] $args[1]
}

for ($i=0; $i -lt $b; $i++) {
    write-host $a " " -NoNewline
}

write-host ""