<?php 
     $data = [
        [
          "y" => 10,
          "width" => 40,
          "color" => "red"
        ],
        [
          "y" => 30,
          "width" => 50,
          "color" => "lime"
        ],
        [
          "y" => 50,
          "width" => 20,
          "color" => "aqua"
        ],
        [
          "y" => 70,
          "width" => 60,
          "color" => "orange"
        ],
    ];

    function generateRectangle($param) {
        echo "<rect width='{$param['width']}' height='15' x='10' y='{$param['y']}' fill='{$param['color']}' />";
    }
 
    function generateSVG($func, $params) {
        echo '<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="200" height="150" >';
            forEach($params as $param) {
                $func($param);
            }
        echo "</svg>";
    }

    function fibonacci($n) {
        if ($n === 1 || $n === 2)
            return $n - 1;
        return fibonacci($n - 1) + fibonacci($n - 2);
    }

    $n = $_GET['n'] ?? '';
    $error = '';
    $fib = 0;


    if ($n === '' || filter_var($n, FILTER_VALIDATE_INT) === false || $n < 2) {
        $error = "To calculate the nth Fibonacci number add this to the url (replacing `value` with the your input): `?n=value`";
    } else {
        $fib = fibonacci($n);
    }
?>


<h1>Task 1</h1>
<?= generateSVG('generateRectangle', $data) ?>

<h1>Task 2</h1>
<?php 
    echo $error;
    echo $fib
?>

<h1>Task 3</h1>


<form>
  Date of issue:
  <input type="date">
  <button type="submit">Send</button>
</form>