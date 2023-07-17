<?php
    $places = [
        "Budapest"          => ["x" => 43, "y" => 38, "next" => ["Cegléd", "Székesfehérvár", "Eger"]],
        "Cegléd"            => ["x" => 55, "y" => 50, "next" => ["Budapest", "Szolnok", "Kecskemét"]],
        "Szolnok"           => ["x" => 60, "y" => 52, "next" => ["Cegléd"]],
        "Eger"              => ["x" => 61, "y" => 25, "next" => ["Budapest", "Miskolc"]],
        "Miskolc"           => ["x" => 67, "y" => 20, "next" => ["Eger", "Nyíregyháza"]],
        "Nyíregyháza"       => ["x" => 81, "y" => 23, "next" => ["Miskolc", "Debrecen"]],
        "Debrecen"          => ["x" => 78, "y" => 38, "next" => ["Nyíregyháza", "Szolnok"]],
        "Kecskemét"         => ["x" => 52, "y" => 60, "next" => ["Cegléd", "Szeged"]],
        "Szeged"            => ["x" => 59, "y" => 79, "next" => ["Kecskemét"]],
        "Tatabánya"         => ["x" => 33, "y" => 33, "next" => ["Budapest", "Győr", "Veszprém"]],
        "Győr"              => ["x" => 22, "y" => 32, "next" => ["Tatabánya", "Sopron", "Szombathely"]],
        "Sopron"            => ["x" => 7,  "y" => 31, "next" => ["Győr", "Szombathely"]],
        "Szombathely"       => ["x" => 8,  "y" => 49, "next" => ["Sopron", "Győr", "Veszprém"]],
        "Székesfehérvár"    => ["x" => 32, "y" => 50, "next" => ["Budapest", "Veszprém"]],
        "Veszprém"          => ["x" => 26, "y" => 52, "next" => ["Székesfehérvár", "Tatabánya", "Szombathely", "Kaposvár"]],
        "Pécs"              => ["x" => 31, "y" => 87, "next" => ["Kaposvár"]],
        "Kaposvár"          => ["x" => 25, "y" => 74, "next" => ["Pécs", "Veszprém"]],
    ];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <title>Task 4</title>
</head>
<body>
    <h1>Task 4: Visited cities</h1>

    <div id="wrapper">
        <div id="map">
            <img src="./hungary.jpg">
        </div>
        <div class="pin" style="top: 20%; left: 70%; background-color: lightgray;"></div>
        <div class="pin" style="top: 50%; left: 50%; background-color: lightgray;"></div>
        <div class="pin" style="top: 80%; left: 30%; background-color: lightgray;"></div>
    </div>

    <b>Path: </b> ???
    
    <div id="congrats">
        Congratulations, you've visited all major cities in Hungary!
    </div>
</body>
</html>
