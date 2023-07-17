<?php 
    include_once 'storage.php';
    $search = $_GET['search'] ?? '';
    $stor = new Storage(new JsonIO('contacts.json'));
    $data = $stor->findAll();

    //* It is good to do all the processing on the server side
    $filter_data = [];
    foreach ($data as $d) {
        if ($search === '' ||  strpos($d['name'], $search) !== false) {
            $filter_data[] = [
                'name' => $d['name'],
                'job' => $d['job'],
                'email' => $d['email'],
                'phone' => $d['phone'],
            ];
        }
    }

    //* sorting
    usort($filter_data, function($a, $b) {
        return strcmp($a['name'], $b['name']); //* spaceship operator <=>, return -1, 0, 1 
    });

    echo json_encode($filter_data, JSON_PRETTY_PRINT); //* returning
    // echo json_encode($data, JSON_PRETTY_PRINT); //* returning
?>