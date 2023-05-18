<?php

    // use shorter names
    //* Null coalescing operator ` ?? '' `, if it is not null, returns the value, else the ''

    $fullname = $_POST['fullname'] ?? ''; 
    $email = $_POST['email'] ?? '';
    $age = $_POST['age'] ?? '';
    $accept = $_POST['accept'] ?? false;
    $accept = filter_var($accept, FILTER_VALIDATE_BOOLEAN); // If the value is 'true', 'one', 'on' or yes, returns true
    $errors = [];

    //* only check the fields if there is a field to check, $_POST
    //* if the page has sent something
    if ($_POST) {
        if ($fullname === '') {
            $errors['fullname'] = "Full name is required  </br>";
        } else if (count(explode(' ', $fullname)) < 2) {
            $errors['fullname'] = "Full name must be 2 words at least. </br>";
        }

        //* use filter validators
        if ($email === '') {
            $errors['email'] = "Email is required";
        } else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors['email'] = "Email must be valid";
        }

        if ($age === '') {
            $errors['age'] = "Age is required";
        } else if (filter_var($age, FILTER_VALIDATE_INT) === false) { //* validate int, float return a value so we need to check another way
            $errors['age'] = "Age is not an integer!";
        }
    
        if (!$accept)
            $errors['accept'] = "Must be checked";
        // print_r($errors);

        $errors = array_map(fn($e) => "<span style='color:red'> $e</span>", $errors);
    }



    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <br>
    <br>
    <i>'novalidate' is used, if I do not want browser level validation. Because if there is an error the browser will not even accept it to be sent!</i> <br>
    <form action="validate.php" method="POST" novalidate>
        Full name: <input type="text" name="fullname" value="<?= $fullname ?>"> <?= $errors["fullname"] ?? '' ?> <br>
        Email: <input type="email" name="email"> <?= $errors["email"] ?? '' ?> <br>
        Phone number: <input type="text" name="phone"> <?= $errors["phone"] ?? '' ?> <br>
        Age: <input type="number" name="age"> <?= $errors["age"] ?? '' ?> <br>
        <input type="checkbox" name="accept"> Accept Tos  -> <?= $errors["accept"] ?? '' ?> 
        <button type='submit'>Submit</button>
    </form>
</body>
</html>