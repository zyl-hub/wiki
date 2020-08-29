import requests

# step1 指定url

url = 'https://www.sogou.com/'

# step2 发请求
response = requests.get(url=url)

# step3 获取响应数据字符串形式
page_text = response.text
print(page_text)

# step4 持久化存储
with open('./sogou.html','w',encoding='utf-8') as fp:
    fp.write(page_text)
print("done!")
