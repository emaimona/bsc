param([parameter(Mandatory=$true)]$path)

$text = get-content $path

foreach( $row in $text) {
    $copy = $row.split()

    write-host $copy[2] $copy[1] $copy[0]
}