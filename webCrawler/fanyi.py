import requests
import json
# url
post_url = 'https://fanyi.baidu.com/sug'
word = input('enter a word')
data = {
    'kw':word
}
# UA伪装
headers = {
    'User-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36'
}
# 请求发送
response = requests.post(url=post_url, data=data, headers=headers)
# 获取响应数据
# json方法返回对象，确实响应数据是json
dic_obj = response.json()
# print(dic_obj)

# 持久化存储
fileName = word + '.json'
fp = open(fileName, 'w', encoding='utf-8')
json.dump(dic_obj, fp=fp, ensure_ascii=False)
