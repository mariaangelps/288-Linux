import requests
from pymongo import MongoClient
from bs4 import BeautifulSoup

url="https://finance.yahoo.com/most-active"
response=requests.get(url)
print("Status code:",response.status_code)

headers = {
"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"
}

response = requests.get(url, headers=headers)
html=response
soup=BeautifulSoup("html.parser")
# establish the connection
client = MongoClient()

db=client["soup"]

