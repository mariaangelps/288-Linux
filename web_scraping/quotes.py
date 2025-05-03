import requests
from pymongo import MongoClient
from bs4 import BeautifulSoup

url="https://quotes.toscrape.com"
response=requests.get(url)
print("Status code:",response.status_code)

#get the html code, por eso se pone content
soup=BeautifulSoup(response.content,"html.parser")
tag = soup.html.head
print(tag)

#Si pongo solo div, me va a salir mas tags
#quotes=soup.find_all("div")
#therefore hago lo siguiente, especifico
#all div tags que tienen clase quote
quotes=soup.find_all("div",{"class":"quote"})
print("All divs: \n",quotes)
doc=[]
#for evry div element find a tag called small, and span whoch class is author  and text and we want to extract the text idnside pf it
#therefore we use (.string)
for i in quotes:
    quote=i.find("span",{"class":"text"}).string
    author=i.find("small",{"class":"author"}).string
    doc.append({"quote":quote,"author:":author})

print(doc)

#