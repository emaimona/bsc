param([int]$x)

function to_bin($n) {
    $arr = @()

    while ($n -gt 0) {
        #write-host $n   $($n %2)
        $arr += [int] $n % 2
        $n =  [math]::floor($n / 2)
        
    }
    return $arr
}


$bin = to_bin($x)
write-host $($bin[-1..-$bin.length] -join '')
