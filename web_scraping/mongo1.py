
from pymongo import MongoClient

#coonnect to the mongoclient
client=MongoClient()

#select the database
db=client["student"]

#select the colelction/table
collection=db["person"]

#insertion
data={"name": "CS288", "Section":"002"}
collection.insert_one(data)

#insertion