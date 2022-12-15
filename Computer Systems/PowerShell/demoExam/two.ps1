
$file = $args[0]
$substring = $args[1]

if(Test-Path -Path ".\NewFile.txt"){
    Remove-Item .\NewFile.txt
}

New-Item -Path "NewFile.txt" -ItemType File
$content = Get-Content $file 

foreach ($i in $content){
    if($i -match "^.*$substring.*$"){
        Add-Content .\NewFile.txt "$i"
    }
}