import requests
import re
import sys
import os
from urllib.request import quote
from urllib import parse
from bs4 import BeautifulSoup
url = 'http://www.imomoe.in/search.asp'
str1 = str(input("请输入你想查找的动漫名称："))
print('你要找的是：'+str1)

data1 = {'searchword': str1.encode('gbk')}
headers = {'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
           'Accept-Encoding': 'gzip, deflate',
           'Accept-Language': 'zh-CN,zh;q=0.9',
           'Cache-Control': 'max-age=0',
           'Connection': 'keep-alive',
           'Content-Length': '35',
           'Content-Type': 'application/x-www-form-urlencoded',
           'Cookie': 'first_h=1593160109666; count_h=1; first_m=1593160109672; count_m=1; __music_index__=1; UM_distinctid=172efbe0d7a395-09561d517e994c-4353760-144000-172efbe0d7b51e; CNZZDATA1260742008=389617554-1593155904-null%7C1593155904; Hm_lvt_38c112aee0c8dc4d8d4127bb172cc197=1592459749,1592485557,1593157823,1593158827; Hm_lpvt_38c112aee0c8dc4d8d4127bb172cc197=1593160110; bdshare_firstime=1593160109768',
           'Host': 'www.imomoe.in',
           'Origin': 'http://www.imomoe.in',
           'Referer': 'http://www.imomoe.in/search.asp',
           'Upgrade-Insecure-Requests': '1',
           'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'}
print(data1)

text = requests.post(url, data=data1, headers=headers)
if text.status_code == 200:
    print("获取结果成功！")

part = re.compile(
    '<h2><a href="(.*)" target="_blank" title="(.*)">.*</a></h2>')
urlli = part.findall(text.content.decode('gbk'))
# print(type(urlli))
# print(urlli)
for i in urlli:
    print(i)
choose = int(input("请选择你需要下载的内容编号："))
print(urlli[choose-1][0], urlli[choose-1][1])

url = 'http://www.imomoe.in'+urlli[choose-1][0]
text = requests.get(url).content.decode('gbk')
soup = BeautifulSoup(text)
src = str(soup.find("div", id="play_0"))
pattern2 = re.compile(r'<a href="(.+?)" target="_blank" title=".+?">(.+?)</a>')
addr = pattern2.findall(src)
print("总集数为："+str(len(addr)))
# print(addr)

url = 'http://www.imomoe.in'+addr[0][0]
text = requests.get(url).content.decode('gbk')
soup2 = BeautifulSoup(text)
data = soup2.find('div', class_="player")
part = re.compile(r'<script src="(.+)?" type="text/javascript"></script>')
playdata = part.findall(str(data))[0]
print(playdata)
url = 'http://www.imomoe.in'+playdata
text = text = requests.get(url).content.decode('gbk')
# print(text)

src2 = text[18::].split(',urlinfo')[0]
urllist = eval(src2)[0]
urllist.pop(0)
# print(urllist)


def geturl():
    a = []
    for i in urllist[0]:
        nameurl = i.split('$')[0], i.split('$')[1]
        a.append(nameurl)
    return a


headers2 = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'}
print(geturl())
path = 'E:\动漫\{}'.format(urlli[choose-1][1])
isExists = os.path.exists(path)
# 判断结果
if not isExists:
    # 如果不存在则创建目录
    # 创建目录操作函数
    os.makedirs(path)
    print(path + ' 创建成功')
else:
    # 如果目录存在则不创建，并提示目录已存在
    print(path + ' 目录已存在')


def download():
    for i in geturl():
        try:
            content = requests.get(i[1], headers=headers2).content
            print(i[0])
            print(urlli[choose-1][1])
            with open(r'E:\动漫\{}\{}.mp4'.format(urlli[choose-1][1], i[0]), 'wb') as f:
                f.write(content)
                print('success')
        except:
            continue
            print("下载失败！")


download()
