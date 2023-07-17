<?php
    include_once('storage.php');
    $stor = new Storage(new JsonIO('cars.json'));
    $cars = $stor->findAll();

    if ($_GET) {

        $id = $_GET['id'] ?? '';
        $car = $stor->findById($id);

        if ($id == '' || !isset($car)) {
            header('location: index.php');
            exit();
        }

        $number = $car['number'];
        $name = $car['name'];

        if ($number > 1) {
            $number = $number - 1;
        }

        $stor->update($id, [
            'id' => $id,
            'name' => $name,
            'number' => $number
        ]);
    }
    header('location: index.php');

?>
