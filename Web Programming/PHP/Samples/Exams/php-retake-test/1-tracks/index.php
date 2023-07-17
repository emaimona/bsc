<?php
$tracks = [
  [ "id" => 1,  "from" => "Írottkő",            "to" => "Sárvár",             "length" => 70.2, "elevation" => 430,  "time" => 1097 ],
  [ "id" => 2,  "from" => "Sárvár",             "to" => "Sümeg",              "length" => 71.9, "elevation" => 280,  "time" => 1106 ],
  [ "id" => 3,  "from" => "Sümeg",              "to" => "Keszthely",          "length" => 47.5, "elevation" => 810,  "time" => 794 ],
  [ "id" => 4,  "from" => "Keszthely",          "to" => "Tapolca",            "length" => 25.7, "elevation" => 470,  "time" => 433 ],
  [ "id" => 5,  "from" => "Tapolca",            "to" => "Badacsonytördemic",  "length" => 15.7, "elevation" => 330,  "time" => 269 ],
  [ "id" => 6,  "from" => "Badacsonytördemic",  "to" => "Nagyvázsony",        "length" => 41,   "elevation" => 1260, "time" => 741 ],
  [ "id" => 7,  "from" => "Nagyvázsony",        "to" => "Városlőd",           "length" => 22.1, "elevation" => 400,  "time" => 372 ],
  [ "id" => 8,  "from" => "Városlőd",           "to" => "Zirc",               "length" => 38.7, "elevation" => 1020, "time" => 683 ],
  [ "id" => 9,  "from" => "Zirc",               "to" => "Bodajk",             "length" => 44.8, "elevation" => 890,  "time" => 760 ],
  [ "id" => 10, "from" => "Bodajk",             "to" => "Szárliget",          "length" => 48.5, "elevation" => 1160, "time" => 843 ],
  [ "id" => 11, "from" => "Szárliget",          "to" => "Dorog",              "length" => 67.2, "elevation" => 1950, "time" => 1204 ],
  [ "id" => 12, "from" => "Dorog",              "to" => "Piliscsaba",         "length" => 18.6, "elevation" => 440,  "time" => 322 ],
  [ "id" => 13, "from" => "Piliscsaba",         "to" => "Hűvösvölgy",         "length" => 21.7, "elevation" => 480,  "time" => 373 ],
  [ "id" => 14, "from" => "Hűvösvölgy",         "to" => "Rozália téglagyár",  "length" => 13.9, "elevation" => 450,  "time" => 253 ],
  [ "id" => 15, "from" => "Rozália téglagyár",  "to" => "Dobogókő",           "length" => 22.3, "elevation" => 1000, "time" => 434 ],
  [ "id" => 16, "from" => "Dobogókő",           "to" => "Visegrád",           "length" => 24.2, "elevation" => 510,  "time" => 414 ],
  [ "id" => 17, "from" => "Nagymaros",          "to" => "Nógrád",             "length" => 38.1, "elevation" => 1610, "time" => 732 ],
  [ "id" => 18, "from" => "Nógrád",             "to" => "Becske",             "length" => 51.7, "elevation" => 1560, "time" => 931 ],
  [ "id" => 19, "from" => "Becske",             "to" => "Mátraverebély",      "length" => 67.3, "elevation" => 1720, "time" => 1181 ],
  [ "id" => 20, "from" => "Mátraverebély",      "to" => "Mátraháza",          "length" => 25.9, "elevation" => 1170, "time" => 505 ],
  [ "id" => 21, "from" => "Mátraháza",          "to" => "Sirok",              "length" => 21.7, "elevation" => 970,  "time" => 422 ],
  [ "id" => 22, "from" => "Sirok",              "to" => "Szarvaskő",          "length" => 17.5, "elevation" => 340,  "time" => 297 ],
  [ "id" => 23, "from" => "Szarvaskő",          "to" => "Putnok",             "length" => 54.9, "elevation" => 1880, "time" => 1012 ],
  [ "id" => 24, "from" => "Putnok",             "to" => "Bódvaszilas",        "length" => 63.9, "elevation" => 1755, "time" => 1740 ],
  [ "id" => 25, "from" => "Bódvaszilas",        "to" => "Boldogkőváralja",    "length" => 65,   "elevation" => 850,  "time" => 1059 ],
  [ "id" => 26, "from" => "Boldogkőváralja",    "to" => "Sátoraljaújhely",    "length" => 52.7, "elevation" => 1680, "time" => 959 ],
  [ "id" => 27, "from" => "Sátoraljaújhely",    "to" => "Hollóháza",          "length" => 46.4, "elevation" => 1280, "time" => 825 ],
];

$lengthSum = array_sum(array_column($tracks, "length"));
$elevationSum =  array_sum(array_column($tracks, "elevation"));
$timeSum = array_sum(array_column($tracks, "time")) / 60;

// largest distance value
$largestDistance = 0;
$largestSteepness = 0;
$largestElevation = 0;
$maxVelocity = 0;
$minVelocity = 0;

foreach($tracks as $d) {
  $largestDistance = max($largestDistance, $d["length"]);
  $largestElevation = max($largestElevation, $d["elevation"]);
  $largestSteepness = max($largestSteepness, $d["elevation"] / $d["length"]);
  $maxVelocity = max($maxVelocity, $d["length"] / $d["time"] * 60);
  $minVelocity = min($maxVelocity, $d["length"] / $d["time"] * 60);
}

function hueStyle($field, $max) {
  return "background-color: hsla(" . round(120 - ($field * 100) / $max * 1.2) . ", 100%, 60%, 0.5)";
}

$vHueStyle = function ($field) use ($maxVelocity, $minVelocity) {
  $percentage = ($field - $minVelocity) / ($maxVelocity - $minVelocity) * 100;
  $hue = 120 - ($percentage * 1.2);
  return "background-color: hsla(" . round($hue) . ", 100%, 60%, 0.5)";
};

?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="index.css">
  <title>Task 1</title>
</head>
<body>
  <h1>Task 1: Tracks</h1>
  <table>
    <thead>
      <tr>
        <th>Id</th>
        <th>From - to</th>
        <th>Length (km)</th>
        <th>Elevation (m)</th>
        <th>Time (h)</th>
        <th>Steepness (m/km)</th>
        <th>Velocity (km/h)</th>
      </tr>
    </thead>
    <tbody>
      <?php foreach($tracks as $d): ?>
        <?php
          $steepness = number_format($d['elevation'] / $d['length'], 1);
          $velocity = number_format(($d["length"]/$d["time"]*60), 1);
          $time = number_format($d['time'] / 60, 1);
          ?>
        <tr>
          <td>#<?= $d["id"] ?></td>
          <td><?= $d['from'] ?> - <?= $d["to"] ?></td>
          <td style="<?= hueStyle($d['length'], $largestDistance) ?>; ""><?= $d['length'] ?></td>
          <td style="<?= hueStyle($d['elevation'], $largestElevation) ?>; " ><?= $d['elevation'] ?></td>
          <td><?= $time?></td>
          <td style="<?= hueStyle($steepness, $largestSteepness) ?>; "><?= $steepness ?></td>
          <td style="<?= $vHueStyle($velocity) ?>; "><?= $velocity?></td>
        <?php endforeach; ?>
    </tbody>
    <tfoot>
      <tr>
        <td colspan="2">Sum</td>
        <td><?= $lengthSum?> </td>
        <td><?= $elevationSum?></td>
        <td><?= $timeSum?> </td>
        <td></td>
        <td></td>
      </tr>
    </tfoot>
  </table>
</body>
</html>