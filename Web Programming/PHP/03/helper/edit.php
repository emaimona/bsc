
<?php
    $data = json_decode(file_get_contents('data.json'), true);
    $id = $_GET['id'] ?? -1;

    //* isset is used to check if the variable exists

    if ($id == -1 || !isset($data[$id])) { //* check if the id is valid
        header('location: index.php');
        exit(); //* is not always needed, but is a good practice -> // this exits the execution of this script
    } else if ($_POST) { //* check if was a POST
        $data[$id] = [
            'name' => $_POST['name'],
            'year' => intval($_POST['year']), // WARNING: intval('banana') === 0
            'height' => floatval($_POST['height']),
            'student' => isset($_POST['student']),
        ];

        //* Writing the content back to the file
        file_put_contents('data.json', json_encode($data, JSON_PRETTY_PRINT));
        header('location: index.php');
    }
?>

<h1>Edit data</h1>
<form action="edit.php?id=<?= $id ?>" method="POST">
    Name: <input type="text" name="name" value="<?= $data[$id]['name'] ?>" > <br>
    Year: <input type="text" name="year" value="<?= $data[$id]['year'] ?>"> <br>
    Height: <input type="text" name="height" value="<?= $data[$id]['height'] ?>"> <br>
    Student: <input type="checkbox" name="student" value="<?= $data[$id]['student'] ?>"> <br>
    <button type="submit"> Send </button>
</form>
