<?php
    $data = json_decode(file_get_contents('data.json'), true);
    $id = $_GET['id'] ?? -1;

    //* isset is used to check if the variable exists

    if ($id == -1 || !isset($data[$id])) { //* check if the id is valid
        header('location: index.php');
        exit(); //* is not always needed, but is a good practice -> // this exits the execution of this script
    } else {
        unset($data[$id]); // remove 

        //* Writing the content back to the file
        file_put_contents('data.json', json_encode($data, JSON_PRETTY_PRINT));
        header('location: index.php');
    }
?>