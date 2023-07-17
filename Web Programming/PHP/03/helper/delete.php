<?php
    include_once('storage.php');
    $stor = new Storage(new JsonIO('data.json'));
    $id = $_GET['id'] ?? -1;

    //* isset is used to check if the variable exists

    if ($id == -1) { //* check if the id is valid
        header('location: index.php');
        exit(); //* is not always needed, but is a good practice -> // this exits the execution of this script
    } else {
        $stor -> delete($id);
        header('location: index.php');
    }
?>