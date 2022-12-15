param([string]$path)

$text = @()
$text = get-content $path
for ($i=$text.count-1; $i -ge 0; $i--) {
    write-host $text[$i]
}