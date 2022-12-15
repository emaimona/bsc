param([parameter(Mandatory=$true)][string]$w, [parameter(Mandatory=$true)][int]$n)

for ($i=0; $i -lt $n; $i++) {
    if ($w.Length -lt $n) {
        write-host $w
    } else {
        write-host $w.Substring(0,$n)
    }
}
