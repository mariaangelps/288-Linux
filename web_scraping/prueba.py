import requests 
from bs4 import BeautifulSoup
import re

#imaginemos que esta es la pagina a la que le vamos. aahcer web scripting
html_doc= """
<html>
<head>
<title>
sample page
</title>
</head>
<body>
<p> Hola, esto si es nice, no me gusta c </p>
<a> href="google.com"> link</a>
<a> second link</a>
<h1> qst heading </h1>

</body>
</html>
"""
#Create python Soup Object
#soup=BeautifulSoup(file,parsing technique)
soup = BeautifulSoup(html_doc,"html.parser")

print("\n")
#to traverse head, get head tag
tag = soup.html.head
print("Head tag: \n",tag)

#replace all null values with empty str
html_doc.replace("\n","")
print("Replace null values:",tag)
print("\n")

tag2=soup.html.head.title
print("Title tag:",tag2)
print("\n")

#what if we want to stract sample page 
tag3=soup.html.head.title.string
print("Title tag:",tag3)

print("\n")

tag4=soup.body
print("Body tag: ",tag4.name)
print("\n")

#print out t---->?
tag5=soup.a
print("What is inside anchor: ",tag5.attrs)
print("\n")

#text inside those tags
tag6=soup.p
print("Lo que esta dentro del parapgarph: ",tag6.string)
print("\n")

tag7=soup.body.contents
print("THIS IS THE CONTENT: ", tag7)
print("\n")

for i in soup.body.children:
    print("Children Iteration: ",i)
    print("\n")

tag_parent=soup.body.parent
print("TAG PARENT: ",tag_parent)

#find and find all to search for a tag or multiple tags
tag8=soup.find_all('a')
print("Ocurrencias de anchor: ",tag8)

#primera ocurrencia de a
tag9=soup.find('a')
print("First occurrence of anchor: ",tag9)

tag10=soup.body.find_all(re.compile('[hH][0-9]+'))
print("Regex: ",tag10)