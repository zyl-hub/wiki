import requests
from bs4 import BeautifulSoup

headers = {
    'User-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36'
}

url = 'https://bing.ioliu.cn/'

response = requests.get(url = url, headers = headers)

page_text = response.text

print(page_text)
