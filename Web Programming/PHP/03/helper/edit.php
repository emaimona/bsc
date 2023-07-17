
<?php

    $id = $_GET['id'] ?? -1;
    include_once('storage.php');
    $stor = new Storage(new JsonIO('data.json'));
    //* isset is used to check if the variable exists

    $data = $stor -> findById($id);
    
    if ($id == -1 || !isset($data)) { //* check if the id is valid
        header('location: index.php');
        exit(); //* is not always needed, but is a good practice -> // this exits the execution of this script
    } else if ($_POST) { //* check if was a POST
        $stor -> update($id, [
            'name' => $_POST['name'],
            'year' => intval($_POST['year']), // WARNING: intval('banana') === 0
            'height' => floatval($_POST['height']),
            'student' => isset($_POST['student']),
        ]);

        header('location: index.php');
    }

?>

<h1>Edit data</h1>
<form action="edit.php?id=<?= $id ?>" method="POST">
    Name: <input type="text" name="name" value="<?= $data['name'] ?>" > <br>
    Year: <input type="text" name="year" value="<?= $data['year'] ?>"> <br>
    Height: <input type="text" name="height" value="<?= $data['height'] ?>"> <br>
    Student: <input type="checkbox" name="student" value="<?= $data['student'] ?>"> <br>
    <button type="submit"> Send </button>
</form>
