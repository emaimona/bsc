<?php
    include_once('storage.php');
    $stor = new Storage(new JsonIO('cars.json'));
    $cars = $stor->findAll();

    if ($_GET) {
        $name = $_GET['name'] ?? ''; 
        $number = $_GET['number'] ?? ''; 
        
        if ($op == '') {
            $stor->add([
                'name' => $name,
                'number' => $number
            ]);
        } 

        header('location: index.php');
        exit();
    }
?>