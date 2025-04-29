import requests

url="https://www.google.com"

# url="https://www.amazon.com" -> code de 503
#if we wanted to do post-> submit
#requests.post(url)
#request module, tenemos que hacer que sea stored en una var
response=requests.get(url)
print("Status code:",response.status_code)

#print headers
print("Headers:",response.headers)

#print type of server
print("Name of the key, type of server: ",response.headers['Server'])

#print the content-> extract daya in byte ->literal byte code sent by server
print("byte code:", response.content)

#extract data as text, string format, same as content pero en string en vez de ser byte
print("byte code:", response.text)

"""If we were to download the data to a local machine, we would do it this way"""
#abrimos y creamos un file llaado google.html
#write in binary format ->wb stands for

#f=open("google.html","wb")
#f.write(response.content)
#f.close()

f=open("google.html","wb")
f.write(response.text)
f.close()