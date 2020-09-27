import requests

r = requests.get("https://www.baidu.com")
print(r.status_code)
type(r)
print(r.headers)
r.encoding = 'utf-8'
print(r.text)