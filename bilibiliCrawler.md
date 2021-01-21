今天发现了一个较为好用的[bilibili视频数据爬取python第三方库](https://github.com/Passkou/bilibili_api)

# install

pip install bilibili_api

# usage

``` python
from bilibili_api import video
print('title', video.get_video_info(bvid=bvid[i])['title'])
print('view', video.get_video_info(bvid=bvid[i])['stat']['view'])
print('danmu', video.get_video_info(bvid=bvid[i])['stat']['danmaku'])
print('reply', video.get_video_info(bvid=bvid[i])['stat']['reply'])
print('favorite', video.get_video_info(bvid=bvid[i])['stat']['favorite'])
print('coin', video.get_video_info(bvid=bvid[i])['stat']['coin'])
print('share', video.get_video_info(bvid=bvid[i])['stat']['share'])
print('like', video.get_video_info(bvid=bvid[i])['stat']['like'])
danmu = video.get_danmaku(bvid=bvid[i])
for _ in danmu:
    print(_)
comments_generator = video.get_comments_g(bvid[_])
comments = []
for comment in comments_generator:
    comments.append(comment)
for _ in range(comments):
    print(comments[_]['content']['message'])
```
