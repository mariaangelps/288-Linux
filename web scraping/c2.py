import requests 
from bs4 import BeautifulSoup

#imaginemos que esta es la pagina a la que le vamos. aahcer web scripting
html_doc= """
<html>
<head>
<title>
sample page
</title>
<body>
<p> Hola, esto si es nice, no me gusta c </p>
<a> href="google.com"> link</a>
</body>
</head>
</html>
"""
#Create python Soup Object
#soup=BeautifulSoup(file,parsing technique)
soup = BeautifulSoup(html_doc,"html.parser")

#to traverse head, get head tag
tag = soup.html.head

#replace all null values with empty str
html_doc.replace("\n","")
print("Head tag:",tag)

tag2=soup.html.head.title
print("Title tag:",tag2)

#what if we want to stract sample page 
tag3=soup.html.head.title.string
print("Title tag:",tag3)