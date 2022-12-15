param([parameter(Mandatory=$true)][int]$n)

for ($i=$n-1; $i -gt 0; $i--) {
    $n *= $i;
}

write-host $n