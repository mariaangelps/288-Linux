<?php
require 'vendor/autoload.php';

# establish the connection
$client = new MongoDB\Client();

# select the database
$db = $client->author_quotes;

# select the connection / table
$collection = $db->data;

# CRUD
# insert_one(document);
# insert_many(list of documents);

# update_one();
# update_many();

# find();
# find_one();

# delete_one();
# delete_many();

# documents are represented as arrays in php, more precisely as associate arrays

/*
$customers = ["name" => "john", "location" => "Newark"];
echo $customer["name"];
*/

$result = $collection->find([]);
/*
foreach($result as $document) {
    foreach($document as $key => $value) {
        echo $value;
    }
}
*/
?>

<html>
<head>
    <title> web page </title>
</head>
<body>
    <table border=1>
    <tr>
        <th>Quote</th>
        <th>Author</th>
    </tr>

    <?php
    foreach($result as $document) {
        echo "<tr>";
        foreach($document as $key => $value) {
            echo "<td>" . $value . "</td>";
        }
        echo "</tr>";
    }
    ?>
    </table>
</body>
</html>
