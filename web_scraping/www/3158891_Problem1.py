import requests
from pymongo import MongoClient
from bs4 import BeautifulSoup

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
#thead=soup.find('thead')
tag_th = soup.find_all('th')
t_body =soup.finall('tbody')
#print(tag_th)
for i in tag_th:
    #strip to eliminate spaces

    print(i.text,strip=True)
for i in t_body:
    #2. Extraer los datos de cada columna
    print(i.contents)



#client = MongoClient()

#db=client["soup"]