<?php
// Conectar a MongoDB
$mongo = new MongoDB\Driver\Manager("mongodb://localhost:27017");

// Consultar los datos en la colección 'most_active_stocks'
$query = new MongoDB\Driver\Query([]);
$cursor = $mongo->executeQuery('stock_data2.most_active_stocks', $query);

echo "<html><body>";
echo "<h1>Most Active Stocks</h1>";

// Incluir DataTables CSS y JS
echo '<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.10.21/css/jquery.dataTables.css">';
echo '<script type="text/javascript" charset="utf8" src="https://code.jquery.com/jquery-3.5.1.js"></script>';
echo '<script type="text/javascript" charset="utf8" src="https://cdn.datatables.net/1.10.21/js/jquery.dataTables.js"></script>';

echo "<table id='stockTable' class='display' border='1'>";
echo "<thead><tr><th>Index</th><th>Symbol</th><th>Name</th><th>Price</th><th>Change</th><th>Volume</th></tr></thead>";
echo "<tbody>";

// Recorrer los resultados y mostrar cada fila de datos
$index = 1;  // Iniciar el índice desde 1
foreach ($cursor as $document) {
    echo "<tr>";
    echo "<td>" . $index . "</td>";  // Mostrar el índice
    echo "<td>" . $document->Symbol . "</td>";
    echo "<td>" . $document->Name . "</td>";
    echo "<td>" . $document->Price . "</td>";
    echo "<td>" . $document->Change . "</td>";
    echo "<td>" . $document->Volume . "</td>";
    echo "</tr>";
    $index++;  // Incrementar el índice
}

echo "</tbody>";
echo "</table>";

// Activar DataTables y permitir ordenar por columnas
echo "<script>
$(document).ready(function() {
    $('#stockTable').DataTable({
        'order': [[0, 'asc']]  // Establecer que el orden inicial sea por el índice (columna 0)
    });
});
</script>";

echo "</body></html>";
?>