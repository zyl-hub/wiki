import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import os

chrome_options = Options()
chrome_options.add_argument('--headless')
chrome_options.add_argument('--disable-gpu')
# driver = webdriver.Chrome('E:\\MyPythonProject\\chromedriver.exe', options=chrome_options)  # 这里的路径是因为我没有将chromedriver添加进环境变量，如果你已经添加过，可以删除掉路径。即
driver = webdriver.Chrome(options=chrome_options)


def downloader(link_set):
    headers = {'user-agent': 'Mozilla/5.0',
               }
    for url in link_set:
        res = requests.get(url, headers)

        res.encoding = res.apparent_encoding

        soup = BeautifulSoup(res.text, 'html.parser')

        title = soup.find('div', class_='ptitle l').find('h1').text

        path = r'/home/yl/Downloads/%s.mp4' % title  # 将路径改成自己的保存路径即可
        if not os.path.exists(path):
            for time in ['first', 'second', 'third']:
                try:
                    driver.get(url)
                    iframe = driver.find_elements_by_tag_name('iframe')[1]
                    driver.switch_to.frame(iframe)
                    linksoup = BeautifulSoup(driver.page_source, 'html.parser')
                    mp4_link = linksoup.find(
                        'div', class_='dplayer-video-wrap').find('video')['src']

                    mp4_res = requests.get(mp4_link, headers, stream=True)
                    size = 0
                    chunk_size = 1024
                    content_size = int(mp4_res.headers['content-length'])
                    print('start download {title}, File size: {size:.2f} MB'.format(title=title,
                                                                                    size=content_size/chunk_size/1024))
                    with open(path, 'wb') as mp:
                        for data in mp4_res.iter_content(chunk_size):
                            mp.write(data)
                            size += len(data)
                            print('\r' + '[DOWNLOADING]:%s%.2f%%' %
                                  ('>' * int(size * 50 / content_size), float(size/content_size * 100)), end=' ')
                    print('\r%s Download completed %s time!' % (title, time))
                    break
                except:
                    continue
            if not os.path.exists(path):
                print('Failed Download %s Three times!' % title)
        else:
            print('File %s existed!' % title)


if __name__ == '__main__':
    links = []
    for i in range(7):
        # 这里的链接地址需要自己在樱花动漫上找到自己想下载的资源，复制网址即可，一般变动的是player/后面的数字，下载的集数由range()控制，比如一共12集，将其修改成range(11)即可
        links.append('http://www.imomoe.in/player/36-0-%d.html' % i)
    downloader(links)
