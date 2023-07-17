<?php

  $tId = $_GET['tid'] ?? '';
  $fId = $_GET['fid'] ?? '';
  include_once 'storage.php';
  $stor = new Storage(new JsonIO('tracks.json'));
  $fstor = new Storage(new JsonIO('logs.json'));
  
  $d = $stor->findById($tId);
  $f = $fstor->findById($fId);

  if ($tId === '' || $tId == -1 || $fId === '' | $fId == -1) {
    header('location: index.php');
  }

?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Task 3</title>
  <link rel="stylesheet" href="index.css">
</head>
<body>
  <h1>Task 3: Logbook</h1>
  <a href="index.php">Back to main page</a>
  <h2>Log details</h2>
  <a href="">Edit log</a>
  <dl>
    <dt>Track</dt>
    <dd><?= $d['id']?>. <?= $d['from'] ?> - <?= $d['to']?> </dd>

    <dt>Date</dt>
    <dd><?= $f['date-from'] ?> - <?= $f['date-to']?> </dd>

    <dt>Log</dt>
    <dd><?= $f['log']?></dd>

    <d>Fellows</d
    <dd><?= $f['fellows'] != NULL ? join(',', $f['fellows']): '</br>' ?></dd>

    <dt>Rating</dt>
    <dd><?= $f['rating']?> </dd>
  </dl>

</body>
</html>