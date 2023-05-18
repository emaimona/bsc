<?php 
    $data = json_decode(file_get_contents('3.json'), true);

    if ($_GET) {
        $data[] = [
            'fullname' => "Maimona Emanuel Nzinga",
            'count' => rand(1,100), 
            
        ];
        file_put_contents('3.json', json_encode($data, JSON_PRETTY_PRINT));
        header('Location: 3.php');
    }

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

    <h2>Task 3: File storage</h2>

    <?php 
        foreach($data as $d) {
            echo $d['fullname'] . ' ' . $d['count'];
            echo '<br>';
        }
    ?>

    <br><a style="color:green; font-weight: bold;" href="3.php?insert=1">Insert my record</a>
</body>
</html>
