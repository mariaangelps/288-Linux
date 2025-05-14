import time
from bs4 import BeautifulSoup
from pymongo import MongoClient
import requests

# Setup MongoDB client and collection
client = MongoClient()
db = client["stock_data"]
collection = db["most_active_stocks"]

while True:
    url = "https://finance.yahoo.com/markets/stocks/most-active/"
    
    # Intentar obtener la página desde la URL
    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.content, "html.parser")
        print("Using live data from URL")
    else:
        # Si no se puede obtener, leer el archivo HTML local
        print("Failed to retrieve from URL, using local HTML file")
        with open("most_active.html", "r") as file:
            html_file = file.read()
        soup = BeautifulSoup(html_file, "html.parser")

    # Encontrar las filas de la tabla con los datos de las acciones
    rows = soup.find_all("tr", {"class": "row yf-1570k0a"})
    print(rows)
    """
    doc = []

    # Procesar cada fila para extraer los datos
    for row in rows:
        symbol = row.find("span", {"class": "symbol yf-5ogvqh"}).string
        name = row.find("div", {"class": "leftAlignHeader yf-362rys enableMaxWidth"}).string
        price = float(row.find("fin-streamer", {"data-field": "regularMarketPrice"}).string)
        change = float(row.find("fin-streamer", {"data-field": "regularMarketChange"}).string)
        volume = float(row.find("fin-streamer", {"data-field": "regularMarketVolume"}).string[:-1])  # Eliminar la "M" o "B" si está presente

        stock_data = {"Symbol": symbol, "Name": name, "Price": price, "Change": change, "Volume": volume}
        doc.append(stock_data)

    # Guardar los nuevos datos en MongoDB
    if doc:
        collection.delete_many({})  # Borrar los datos anteriores
        collection.insert_many(doc)  # Insertar los nuevos datos
        print(f"Inserted {len(doc)} new documents.")

    # Esperar 3 minutos antes de la siguiente actualización
    print("Waiting for 3 minutes before the next update...")
    time.sleep(180)
"""