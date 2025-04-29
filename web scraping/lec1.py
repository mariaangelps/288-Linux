import requests

url="https://www.google.com"

#request module, tenemos que hacer que sea stored en una var
response=requests.get(url)
print("Status code:",response.status_code)

#if we wanted to do post-> submit
#requests.post(url)