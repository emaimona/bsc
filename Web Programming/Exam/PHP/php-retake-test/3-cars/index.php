<?php
    include_once('storage.php');
    $stor = new Storage(new JsonIO('cars.json'));
    $cars = $stor->findAll();

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 3 - Cars</title>
    <link rel=stylesheet href="src/index.css">  
</head>
<body>
    <h1>Task 3 - Cars</h1>
    <table>
        <thead>
            <th>Name</th>
            <th>Number</th>
            <th>Action</th>
        </thead>
        <tbody>

            <?php foreach($cars as $c): ?>
                <tr>
                    <td><?= $c['name'] ?></td>
                    <td><?= $c['number'] ?></td>
                    <td>
                        <a href="num_inc.php?id=<?= $c['id'] ?>">➕</a>
                        <a href="num_dec.php?id=<?= $c['id'] ?>">➖</a>
                    </td>
                </tr>
            <?php endforeach; ?>
            <tr>
                <form action="new_car.php" method="GET">
                    <td><input name="name" placeholder="Name" required></td>
                    <td><input name="number" type="number" placeholder="0" required></td>
                    <td><input type="submit" value="Add new car"></td>
                </form>
            </tr>
        </tbody>
    </table>
</body>
</html>