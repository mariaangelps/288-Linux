import requests
from pymongo import MongoClient
from bs4 import BeautifulSoup
import time

client = MongoClient()
db=client["stock_data"]
collection = db["most_active_stocks"]

while True:
    """
    url="https://finance.yahoo.com/most-active"
    response=requests.get(url)
    print("Status code:",response.status_code)

    if response.status_code == 200:
        soup = BeautifulSoup(response.content, "html.parser")
    else:
        #get data from html file

        """
    with open("most_active.html", "r") as file:
        html_file= file.read()

    soup=BeautifulSoup(html_file,"html.parser")

    #1. queremos encontrar primero las columnas symbol, name, price,change and volume
    #to find debugging steps
    html_file.replace("\n","")
    #busco el 1er thead, despues me meto a ese y busco todos los headers de la tabla "th"
    t_head=soup.find('thead')
    tag_th = t_head.find_all('th')

    #print each header
    #for i in tag_th:
        #print(i.text.strip()) #strip to eliminate spaces

    #2. Extraer los datos de la tabla que estan dentro de tbody, obv busco primero la primera occurence de tbody
    t_body =soup.find('tbody')
    t_tr=t_body.find_all('tr') #encuentro tr que seria las rows
    stock_data=[]

    #hago un loop para iterar dentro de cada row, y sacar su columna
    for row in t_tr:
        #identifica cada celda como match de row y columna
        celdas=row.find_all('td')
        #extraer solo las 5 primeras
        if len(celdas) ==5:
            data = {
                    "symbol": celdas[0].text.strip(),
                    "name": celdas[1].text.strip(),
                    "price": celdas[2].text.strip(),
                    "change": celdas[3].text.strip(),
                    "volume": celdas[4].text.strip()
                }
            stock_data.append(data)
        
        if stock_data:
            print("Inserting data into the collection:", stock_data)
            collection.insert_many(stock_data)
            print(f"Inserted {len(stock_data)} new documents.")
        else:
            print("No data to insert.")

        # Esperar 3 minutos antes de la siguiente actualización
        print("Waiting for 3 minutes before the next update...")
        time.sleep(180)  







