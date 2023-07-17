<?php
    $id = $_GET['id'] ?? -1;
    include_once('storage.php');
    $stor = new Storage(new JsonIO('data.json'));
    $data = $stor -> findById($id);
    
    if ($id == -1 || !isset($data)) { 
        header('location: index.php');
        exit();
    }
?>

<h1>Personal data</h1>
<i> When converting a boolean it writes 1 if true and empty ' ' if false </i> <br>
Name: <?= $data['name'] ?> <br>
Year: <?= $data['year'] ?> <br>
Height: <?= $data['height'] ?> <br>
Student: <?= $data['student'] ? 'true' : 'false' ?> <br>

<a href="edit.php?id=<?= $id?>">Edit data</a>
<a href="delete.php?id=<?= $id?>">Delete data</a>