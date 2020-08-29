import requests

# UA伪装
headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36'
}
# UA: User-Agent
url='https://www.sogou.com/web'
# 处理url携带的参数：封装到字典
kw = input('enter a word:')
params = {
    'query':kw
}
# 对指定url发带参数请求
response = requests.get(url=url, params=params,headers=headers)

page_text = response.text
filename = kw+'.html'
with open(filename, 'w', encoding='utf-8') as fp:
    fp.write(page_text)

print(filename,'saved!')
