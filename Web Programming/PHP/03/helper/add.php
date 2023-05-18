
<?php 
    if ($_POST) {
        $data = json_decode(file_get_contents('data.json', true));

        $data[] = [
            'name' => $_POST['name'],
            'year' => intval($_POST['year']), // WARNING: intval('banana') === 0
            'height' => floatval($_POST['height']),
            'student' => isset($_POST['student']), //* we have to check the 'checkbox' because they do not sent any value if its not marked
        ];

        // file_put_contents('data.json', json_encode($data));

        //* JSON_PRETTY_PRINT is use for nice printing

        file_put_contents('data.json', json_encode($data, JSON_PRETTY_PRINT));
        header('location: index.php');
    }

?>


<h1>New Person</h1>
<i>Intval and Floatval are used for conversions</i>
<i><b> Note:</b> intval('banana') is going to be 0, this is why we should validate</i>
<i>There is no 'NaN' is php</i>
<br>

<form action="add.php" method="POST">
    Name: <input type="text" name="name"> <br>
    Year: <input type="text" name="year"> <br>
    Height: <input type="text" name="height"> <br>
    Student: <input type="checkbox" name="student"> <br>
    <button type="submit"> Send </button>
</form>
