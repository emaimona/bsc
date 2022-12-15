[double]$a = read-host "a="
[double]$b = read-host "b="
[double]$c = read-host "c="

if ($a -eq 0) {
    write-host "Not good"
} else {
    $d= $b*$b -4*$a*$c

    if ($d -lt 0) {
        write-host "No solution"
    } else {
        if ($d -eq 0) {
            write-host $(-$b/(2*$a))
        } else {
            $d = [math]::sqrt($d)
            write-host $(-$b-$d/(2*$a))
            write-host $(-$b+$d/(2*$a))
        }
    }
}