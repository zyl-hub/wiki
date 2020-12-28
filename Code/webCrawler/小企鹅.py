import requests
import re
import sys
import os
from bs4 import BeautifulSoup
import pandas
from time import sleep
import numpy as np
from tqdm import tqdm
import random

proxies = {"http": "http://127.0.0.1:7890", "https": "https://127.0.0.1:7890"}

USER_AGENTS = [
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
    "Mozilla/5.0 (Windows; U; Windows NT 6.1; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
    "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0",
    "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; .NET4.0C; .NET4.0E; .NET CLR 2.0.50727; .NET CLR 3.0.30729; .NET CLR 3.5.30729; InfoPath.3; rv:11.0) like Gecko",
    "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0)",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)",
    "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:2.0.1) Gecko/20100101 Firefox/4.0.1",
    "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1",
    "Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; en) Presto/2.8.131 Version/11.11",
    "Opera/9.80 (Windows NT 6.1; U; en) Presto/2.8.131 Version/11.11",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Maxthon 2.0)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; TencentTraveler 4.0)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; The World)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Trident/4.0; SE 2.X MetaSr 1.0; SE 2.X MetaSr 1.0; .NET CLR 2.0.50727; SE 2.X MetaSr 1.0)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; 360SE)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Avant Browser)",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)",
    "Mozilla/5.0 (iPhone; U; CPU iPhone OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
    "Mozilla/5.0 (iPod; U; CPU iPhone OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
    "Mozilla/5.0 (iPad; U; CPU OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
    "Mozilla/5.0 (Linux; U; Android 2.3.7; en-us; Nexus One Build/FRF91) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1",
    "MQQBrowser/26 Mozilla/5.0 (Linux; U; Android 2.3.7; zh-cn; MB200 Build/GRJ22; CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1",
    "Opera/9.80 (Android 2.3.4; Linux; Opera Mobi/build-1107180945; U; en-GB) Presto/2.8.149 Version/11.10",
    "Mozilla/5.0 (Linux; U; Android 3.0; en-us; Xoom Build/HRI39) AppleWebKit/534.13 (KHTML, like Gecko) Version/4.0 Safari/534.13",
    "Mozilla/5.0 (BlackBerry; U; BlackBerry 9800; en) AppleWebKit/534.1+ (KHTML, like Gecko) Version/6.0.0.337 Mobile Safari/534.1+",
    "Mozilla/5.0 (hp-tablet; Linux; hpwOS/3.0.0; U; en-US) AppleWebKit/534.6 (KHTML, like Gecko) wOSBrowser/233.70 Safari/534.6 TouchPad/1.0",
    "Mozilla/5.0 (SymbianOS/9.4; Series60/5.0 NokiaN97-1/20.0.019; Profile/MIDP-2.1 Configuration/CLDC-1.1) AppleWebKit/525 (KHTML, like Gecko) BrowserNG/7.1.18124",
    "Mozilla/5.0 (compatible; MSIE 9.0; Windows Phone OS 7.5; Trident/5.0; IEMobile/9.0; HTC; Titan)",
    "UCWEB7.0.2.37/28/999",
    "NOKIA5700/ UCWEB7.0.2.37/28/999",
    "Openwave/ UCWEB7.0.2.37/28/999",
    "Mozilla/4.0 (compatible; MSIE 6.0; ) Opera/UCWEB7.0.2.37/28/999",
    # iPhone 6：
    "Mozilla/6.0 (iPhone; CPU iPhone OS 8_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/8.0 Mobile/10A5376e Safari/8536.25",
]


def get_request_headers():
    headers = {
        'User-Agent': random.choice(USER_AGENTS),
        # 'Accept':
        # 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
        # 'Accept-language': 'zh-CN,zh;q=0.9',
        # 'Accept-Encoding': 'gzip, deflate,br',
        # 'Connection': 'keep-alive',
    }
    return headers


urls = []
urls.append('https://store.line.me/stickershop/product/13707132/ja')
urls.append('https://store.line.me/stickershop/product/13674820/ja')
urls.append('https://store.line.me/stickershop/product/13674803/ja')
urls.append('https://store.line.me/stickershop/product/13667304/ja')
urls.append('https://store.line.me/stickershop/product/13659475/ja')
urls.append('https://store.line.me/stickershop/product/13654147/ja')
urls.append('https://store.line.me/stickershop/product/13651564/ja')
urls.append('https://store.line.me/stickershop/product/13643359/ja')
urls.append('https://store.line.me/stickershop/product/13619126/ja')
urls.append('https://store.line.me/stickershop/product/13453077/ja')
urls.append('https://store.line.me/stickershop/product/13316730/ja')
urls.append('https://store.line.me/stickershop/product/13354477/ja')
urls.append('https://store.line.me/stickershop/product/13266564/ja')
urls.append('https://store.line.me/stickershop/product/13229231/ja')
urls.append('https://store.line.me/stickershop/product/13229242/ja')
urls.append('https://store.line.me/stickershop/product/13222791/ja')
urls.append('https://store.line.me/stickershop/product/13309899/ja')
urls.append('https://store.line.me/stickershop/product/13216244/ja')
urls.append('https://store.line.me/stickershop/product/13209999/ja')
urls.append('https://store.line.me/stickershop/product/13204441/ja')
urls.append('https://store.line.me/stickershop/product/13082263/ja')
urls.append('https://store.line.me/stickershop/product/12984552/ja')
urls.append('https://store.line.me/stickershop/product/12487868/ja')
urls.append('https://store.line.me/stickershop/product/11889457/ja')
urls.append('https://store.line.me/stickershop/product/10681438/ja')
urls.append('https://store.line.me/stickershop/product/10681430/ja')
urls.append('https://store.line.me/stickershop/product/10681474/ja')
urls.append('https://store.line.me/stickershop/product/10681478/ja')
urls.append('https://store.line.me/stickershop/product/10681467/ja')
urls.append('https://store.line.me/stickershop/product/10637582/ja')
urls.append('https://store.line.me/stickershop/product/10333376/ja')
urls.append('https://store.line.me/stickershop/product/10333374/ja')
urls.append('https://store.line.me/stickershop/product/10317440/ja')
urls.append('https://store.line.me/stickershop/product/10317442/ja')
urls.append('https://store.line.me/stickershop/product/10317446/ja')
urls.append('https://store.line.me/stickershop/product/10317211/ja')
urls.append('https://store.line.me/stickershop/product/10147802/ja')
urls.append('https://store.line.me/stickershop/product/10137149/ja')
urls.append('https://store.line.me/stickershop/product/9887304/ja')
urls.append('https://store.line.me/stickershop/product/9674327/ja')
urls.append('https://store.line.me/stickershop/product/7973660/ja')
urls.append('https://store.line.me/stickershop/product/7135848/ja')
urls.append('https://store.line.me/stickershop/product/7103883/ja')
urls.append('https://store.line.me/stickershop/product/6017043/ja')
urls.append('https://store.line.me/stickershop/product/5341973/ja')
urls.append('https://store.line.me/stickershop/product/5023643/ja')
urls.append('https://store.line.me/stickershop/product/4726927/ja')
urls.append('https://store.line.me/stickershop/product/4270353/ja')
urls.append('https://store.line.me/stickershop/product/4111080/ja')
urls.append('https://store.line.me/stickershop/product/3805102/ja')
urls.append('https://store.line.me/stickershop/product/3651987/ja')
urls.append('https://store.line.me/stickershop/product/3471588/ja')
urls.append('https://store.line.me/stickershop/product/3217669/ja')
urls.append('https://store.line.me/stickershop/product/3114599/ja')
urls.append('https://store.line.me/stickershop/product/1907972/ja')
urls.append('https://store.line.me/stickershop/product/1862778/ja')

pngNums = 1
pngLinks = []
pbar1 = tqdm(total=len(urls))
for i in range(len(urls)):
    print("页面进度：")
    print(urls[i])
    pbar1.update(1)
    attempts0 = 0
    success0 = False
    while attempts0 < 3 and not success0:
        try:
            r = requests.get(urls[i],
                             headers=get_request_headers(),
                             proxies=proxies,
                             timeout=10).text
            success0 = True
        except:
            attempts0 += 1
            if attempts0 == 3:
                break
    soup = BeautifulSoup(r, 'lxml')
    Links = []

    allLinks = soup.find_all('span', class_='mdCMN09Image')

    pattern = re.compile(
        r'http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+'
    )  # 匹配模式
    result = re.findall(pattern, str(allLinks))

    for i in range(len(result)):
        result[i] = result[i][0:len(result[i]) - 16]

    result = list(set(result))

    pbar2 = tqdm(total=len(result))
    for i in range(len(result)):
        print("图片下载进度：")
        pbar2.update(1)
        attempts = 0
        success = False
        while attempts < 3 and not success:

            try:
                png = requests.get(result[i],
                                   headers=get_request_headers(),
                                   proxies=proxies,
                                   timeout=10)
                path = str(pngNums) + '.png'
                with open(path, 'wb') as f:
                    f.write(png.content)
                    pngNums += 1
                    success = True
            except:
                attempts += 1
                print(f"failed {attempts+1} times!")
                if attempts == 3:
                    break
        sleep(2)
    pbar2.close()

pbar1.close()
