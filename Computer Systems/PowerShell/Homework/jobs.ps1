
param([parameter(Mandatory=$true)]$path)

function noViolentPlaces($text) {
    $count = 1

    write-host "Workplaces where no violent acts have been reported: "
    foreach ($row in $text) {
        if ($row -match ".+, 0,.{2}" ) {
            write-host "`t $count   $($row.split(',')[0])"
            $count += 1
        }
    }

    if ($count -eq 1) {
        write-host "`t NONE"
    }
    

    Write-Host
}


function nbrOfGuards($text) {
    $sum = 0

    foreach ($row in $text) {
        $n = [int] $($row.split(', ')[-1])
        $sum += $n
    }
    write-host "Total number of security guards according to the data file provided: $sum"

    Write-Host
}


function getHighest($text) {
    $highest = 0
    foreach ($row in $text) {
        $n = [int] $($row.split(', ')[-2])
        $highest = [math]::max($highest, $n)
    }

    return $highest
}
function highestIncidents($text) {
    $count = 1
    $highest = getHighest($text)

    write-host "The names of the workplaces with the highest number of violent incidents are located, their name(s) and address(es)."

    foreach ($row in $text) {
        $half = $row.split(', ')
        $n = [int] $($half[-2])
        if ($n -eq $highest) {
            write-host "`t$count   $($half[0])    $($half[1])"
            $count++;
        }
    }

    Write-Host
}

if (test-path $path) {
    Write-Host

    $text = @()
    $text += get-content $path
    noViolentPlaces($text)
    nbrOfGuards($text)
    highestIncidents($text)

} else {
    write-host "The file is invalid!"
    exit 1
}

  