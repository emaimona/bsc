param([string]$path)

$text = @()
$text = get-content $path

foreach ($row in $text) {
    write-host $($row[-1..-$row.length] -join '')
}