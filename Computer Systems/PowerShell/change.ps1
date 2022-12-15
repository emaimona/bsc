$content = @()
$content += get-content $args[0]

foreach ($row in $content) {
    $del = $row.split()
    write-host $del[2] $del[1] $del[0]
}