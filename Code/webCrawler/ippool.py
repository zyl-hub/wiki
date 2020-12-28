import requests
import json
from bs4 import BeautifulSoup
import time

headers = {
    'Referer':
    'https://www.kuaidaili.com/free/inha/1/',
    'Cookie':
    '_ga=GA1.2.1075258978.1586877585; _gid=GA1.2.304073749.1587691875; Hm_lvt_7ed65b1cc4b810e9fd37959c9bb51b31=1586877585,1587691875; channelid=0; sid=1587690934346679; Hm_lpvt_7ed65b1cc4b810e9fd37959c9bb51b31=1587692242',
    'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36'
}


def get_ip(url):
    html = requests.get(url, headers)
    if html.status_code == 200:
        print('正在爬取中...')
        time.sleep(2)
        parse_html(html.text)
    else:
        print('Error', url)


def parse_html(text):
    soup = BeautifulSoup(text, 'lxml')
    ips = soup.select('#list tbody tr')
    for line in ips:
        ip = line.select_one('td').text
        port = line.select('td')[1].text
        print(f'[INFO]获取Ip:{ip},Port:{port}......')
        address = f'http://{ip}:{port}'
        proxies = {'http': address, 'https': address}
        verify_ip(proxies)


def verify_ip(proxies):
    try:
        html = requests.get('http://www.baidu.com', proxies=proxies, timeout=3)
        print(f'[SUCCESS]可用代理：{proxies}')
        save_ip(proxies)
    except:
        print(f'[ERROR]代理不可用：{proxies}')


# 写入json数据


def save_ip(proxies):
    # with open('ip_text.txt','a+') as f:
    #     f.write(str(proxies)+'\n')
    #     print('\n[SUCCESS]代理已经写入文本！！！')
    with open('ip_text.json', 'a+', encoding='utf-8') as f:
        d = json.dumps(proxies)
        f.write(d + '\n')
        print('\n[SUCCESS]代理已经写入文本！！！')


def read_txt():
    # with open('ip_text.txt','r',encoding='utf-8') as f:
    #     contents = f.readlines()
    #     for content in contents:
    #         print(content)
    with open('ip_text.json', 'r', encoding='utf-8') as f:
        for line in f:
            try:
                content = json.loads(line.strip())
                # print(content)
                html = requests.get('http://www.baidu.com',
                                    proxies=content,
                                    timeout=3)
                print('[SUCCESS]有效代理', content)
            except:
                print('[ERROR]失效代理', content)


if __name__ == '__main__':
    num = eval(input('请输入要爬取的页数：'))
    for i in range(1, num + 1):
        url = f'https://www.kuaidaili.com/free/inha/{i}/'
        get_ip(url)
    # read_txt()
    # 如果要验证读取代理ip的有效性，可以把read_text()语句前面的四行注释掉，调用read_text()函数即可
