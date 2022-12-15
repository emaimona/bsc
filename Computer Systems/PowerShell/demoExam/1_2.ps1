param([parameter(Mandatory=$true)]    [int]$base,  
        [parameter(Mandatory=$true)]  [int]$counts)


for ($i=0; $i -le $counts; $i++) {
    $power = [math]::Pow($base, $i)
    write-host $power " " -NoNewline
}

write-host ""