<?php
    $data = json_decode(file_get_contents('data.json'), true);
    $id = $_GET['id'] ?? -1;

    //* isset is used to check if the variable exists

    if ($id == -1 || !isset($data[$id])) { //* check if the id is valid

        header('location: index.php');
        exit(); //* is not always needed, but is a good practice -> // this exits the execution of this script
    }
?>

<h1>Personal data</h1>
<i> When converting a boolean it writes 1 if true and empty ' ' if false </i> <br>
Name: <?= $data[$id]['name'] ?> <br>
Year: <?= $data[$id]['year'] ?> <br>
Height: <?= $data[$id]['height'] ?> <br>
Student: <?= $data[$id]['student'] ? 'true' : 'false' ?> <br>

<a href="edit.php?id=<?= $id?>">Edit data</a>
<a href="delete.php?id=<?= $id?>">Delete data</a>