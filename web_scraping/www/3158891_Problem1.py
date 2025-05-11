import requests
from pymongo import MongoClient
from bs4 import BeautifulSoup
import time

url="https://finance.yahoo.com/most-active"
response=requests.get(url)
print("Status code:",response.status_code)

#get data from html file
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
for i in tag_th:
    #strip to eliminate spaces
    print(i.text.strip())

#2. Extraer los datos de la tabla que estan dentro de tbody, obv busco primero la primera occurence de tbody
t_body =soup.find('tbody')
#encuentro tr que seria las rows
t_tr=t_body.find_all('tr')
index = 1  #esto para poder recorrer cada celda

#hago un loop para iterar dentro de cada row, y sacar su columna
for row in t_tr:
    #identifica cada celda como match de row y columna
    celdas=i.find_all('td')
    #extraer solo las 5 primeras
    if len(celdas) ==5:
        data = [i.text.strip() for i in celdas]
        print(f"{index} | {' | '.join(data)}")
        index+=1








#client = MongoClient()

#db=client["soup"]