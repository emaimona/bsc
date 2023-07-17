<?php
  include_once 'storage.php';
  $stor = new Storage(new JsonIO('tracks.json'));
  $fstor = new Storage(new JsonIO('logs.json'));

  if ($_POST) {
    $newFellows = explode(',',$_POST['fellow-text']);

    $fstor -> add([

      'track' => $_POST['track'],
      'date-from' => $_POST['date-from'],
      'date-to' => $_POST['date-to'],
      'log' =>  $_POST['log'],
      'fellows' => array_unique(array_merge($_POST['fellows'], $newFellows)),
      'fellow-text' => $newFellows,
      'rating' => $_POST['rating']
    
    ]);

    header('location: index.php');
  }

  $data = $stor->findAll();
  $fellows = [];
  foreach (array_column($fstor->findAll(), 'fellow-text') as $fellow) {
    $fellows = array_merge($fellows, $fellow);
  }
  $fellows = array_unique($fellows);

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
  <h2>New log</h2>
  <form action="" method="post">
    Track: <br>
    <select name="track" required>
      <?php foreach($data as $d): ?>
      <option value="<?= $d['id']?>"> <?= $d['id']?>. <?= $d['from'] ?> - <?= $d['to']?> </option>
      <?php endforeach; ?>
    </select> <br>
    Date interval: <br>
    <input type="date" name="date-from" required> - <input type="date" name="date-to" required> <br>
    Log: <br>
    <textarea name="log" cols="120" rows="10" placeholder="Write your experiences here..." required></textarea> <br>
    Fellows: <br>
    <?php foreach($fellows as $fellow): ?>
      <input type="checkbox" name="fellows[]" value="<?= $fellow ?>"> <?= $fellow ?> <br>
    <?php endforeach; ?>
    <small>Add new fellows as a comma-separated list:</small> <br>
    <textarea name="fellow-text" cols="20" rows="8" placeholder="fellow1,fellow2"></textarea> <br>
    Rating: <br>
    <input type="radio" name="rating" value="1" required> 1
    <input type="radio" name="rating" value="2"> 2
    <input type="radio" name="rating" value="3"> 3
    <input type="radio" name="rating" value="4"> 4
    <input type="radio" name="rating" value="5"> 5
    <br>
    <button type="submit">Add new track</button>
  </form>
</body>
</html>