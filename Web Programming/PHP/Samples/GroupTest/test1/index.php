<?php 
    $shapes = [
        [
          'type'    => 'rect',
          'params'  => [
            'x' => 0,
            'y' => 0,
            'width' => 50,
            'height' => 50,
            'rx' => 10,
          ]
        ],
        [
          'type'    => 'line',
          'params'  => [
            'x1' => 60,
            'y1' => 100,
            'x2' => 80,
            'y2' => 120,
            'stroke' => 'red',
          ]
        ],
        [
          'type'    => 'line',
          'params'  => [
            'x1' => 80,
            'y1' => 120,
            'x2' => 150,
            'y2' => 50,
            'stroke' => 'red',
          ]
        ],
        [
          'type'    => 'circle',
          'params'  => [
            'cx' => 150,
            'cy' => 100,
            'r' => 20,
          ]
        ],
      ];

     

        $students = json_decode(file_get_contents('students.json'), true);

        //* Now getting files from json
    //   $students = [
    //     ['name' => 'Student1', 'age' => 20],
    //     ['name' => 'Student2', 'age' => 10],
    //     ['name' => 'Student3', 'age' => 30],
    //     ['name' => 'Student4', 'age' => 20],
    //     ['name' => 'Student5', 'age' => 10],
    //   ];

        $age = $_GET['age'] ?? '';

        if ($age === '' || filter_var($age, FILTER_VALIDATE_INT) === false || $age < 0) {
            $customStudents = $students;
        } else {
            $customStudents = array_filter($students, fn($student) => $student['age'] == $age);
        }


      function generateElement($type, $params) {
            if ($type === "rect") {
                echo "<rect x={$params['x']} y=\"0\" width=\"100\" height=\"100\" rx=\"15\" />";
            } else if ($type === "line") {
                echo "<line x1={$params['x1']} y1={$params['y1']} x2={$params['x2']} y2={$params['y2']} stroke={$params['stroke']} />";
            } else if ($type === "circle") {
                echo "<circle cx={$params['cx']} cy={$params['cy']} r={$params['r']} />";
            }
      }


        $errors = [];
        $name = $_POST['name'] ?? '';
        $age = $_POST['age'] ?? '';

        if ($_POST) {
            if ($name === '') {
                $errors[] = 'Name is required';
            }

            if ($age === '') {
                $errors[] = 'Age is required';
            } else if (filter_var($age, FILTER_VALIDATE_INT) === false) {
                $errors[] = 'Age must be an integer';
            }

            if (count($errors) === 0) {
                $students[] = [
                    'name' => $name,
                    'age' => $age,
                ];
                file_put_contents('students.json', json_encode($students, JSON_PRETTY_PRINT));

                header('location: index.php');
            }

        }

        $errors = array_map(fn($e) => "<li style='color:red'> $e</li>", $errors);
?>

<h1>SVG generation (3 points)</h1>

<svg width="200px" height="200px" xmlns="http://www.w3.org/2000/svg">
    <?php 
        forEach($shapes as $shape) {
            generateElement($shape['type'], $shape['params']);
        }
        forEach($data as $rect) {
            generateElement('rect', $rect);
        }
    ?>
</svg>

<br>
<h1>Filtering a list (3,5 pont)</h1>
<?php 
    forEach($customStudents as $student) {
        echo "<li> {$student['name']}({$student['age']}) </li>";
    }
?>


<br>
<h1>Saving student records (3,5 points)</h1>
<h2>New student</h2>
<ul>

<?php 
    forEach($errors as $error) {
        echo $error;
    }
?>
</ul>

<form action="index.php" method="post">
  Name: <input type="text" name="name" value="<?= $name ?? ''?>"/> <br>
  Age: <input type="text" name="age" value="<?= $age ?? ''?>" /> <br>
  <button type="submit">Add student</button>
</form>