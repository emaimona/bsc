
param([string]$n)
function get($x) {
    if ($x -eq "I") {
        return 1;
    }
    if ($x -eq "V") {
        return 5;
    }
    if ($x -eq "X") {
        return 10;
    }
    if ($x -eq "L") {
        return 50;
    }
    if ($x -eq "C") {
        return 100;
    }
    if ($x -eq "D") {
        return 500;
    }if ($x -eq "M") {
        return 1000;
    }

    return 0;
}


$arr = $n.toCharArray()

$len = $arr.length
$prev = 0
$cur = 0
$num = 0

for ($i=$len-1; $i -ge 0; $i-- ) {
    $cur = $(get($arr[$i]))
    if ($prev -eq 0) {
        $sum += $cur
    } else {
        if ($cur -ge $prev) {
            $sum += $cur
        } else {
            $sum -= $cur 
        }
    }
    $prev = $cur
}


write-host $sum