<?php 
  include_once 'storage.php';
  $stor = new Storage(new JsonIO('tracks.json'));
  $fstor = new Storage(new JsonIO('logs.json'));

  $allTracks = $stor->findAll();
  $allFellows = $fstor->findAll();

  $find = function ($id) use($allFellows, $allTracks) {

      $fellows = array_filter($allFellows, function ($f) use($id) {
          return $f['track'] == $id;
      });
      
      if (count($fellows) == 0) return;
      $d = $allTracks[$id];

      echo "<h2>". $d['id'] .".". $d['from'] ."-". $d['to'] . "</h2>";
      foreach($fellows as $fellow) {
        echo "<ul>";
          echo "<a href=\"log.php?fid=". $fellow['id'] ."&tid=". $d['id']. "\"><li>" . $fellow['date-from'] . "-". $fellow['date-to']. "</li></a>";
        echo "</ul>";
      }
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
  <a href="new.php">Add new log...</a>
  
  <?php foreach($allTracks as $t): ?>
    <?= $find($t['id']) ?>
  <?php endforeach; ?>
</body>
</html>