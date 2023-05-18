<?php
    $number = $_GET['number'] ?? '';
    $operation = $_GET['operation'] ?? '';
    $errors = [];

    if ($number === '') {
        $errors[] = 'Number is required';
    } else if (filter_var($number, FILTER_VALIDATE_INT) === false) {
        $errors[] = 'Number must be an integer';
    }

    if ($operation === '') {
        $errors[] = 'Operation is required';
    } else if ( $operation !== 'square' && $operation !== 'cube' ) {
        $errors[] = 'Invalid operation.';
    } else {
        $square = $number * $number;
        $cube = $square * $number;
        $result = ($operation === 'square') ? "The <b>square</b> of $number is <b>$square</b>" : "The <b>Cube</b> of $number is <b>$cube</b>";
    }
    $errors = array_map( fn($e) => "<li> $e </li>", $errors);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <title>PHP GROUP TEST</title>
</head>
<body>
    <h1>PHP GROUP TEST</h1>

    <h2>Task 2: Form input</h2>
    <form action="2.php" method="GET" novalidate>
        <label for="i1">Number:</label>
        <input type="text" name="number" id="i1" value="<?= $number ?? '' ?>">
        <br>
        <label for="i2">Operation:</label>
        <input type="text" name="operation" id="i2" value="<?= $operation ?? '' ?>">
        <br>
        <button type="submit">Calculate</button>
    </form>

    <h2><?= count($errors) ? "Error" : "Result" ?></h2>
    <?php 
        if (count($errors)) {
            echo "<ul>";
            forEach ($errors as $error) {
                echo $error;
            }
            echo "</ul>";

        } else {
            echo $result;
        }
    ?>
</body>
</html>
