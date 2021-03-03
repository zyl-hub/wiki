[[mannual]]

apt出现安装错误

``` shell
E: Could not get lock /var/lib/dpkg/lock-frontend - open (11: Resource temporarly unavailable)

E: Unable to acquire the dpkg frontend lock (/var/lib/dpkg/lock-frontend), is an other process using it?

删除锁定文件，行了

sudo rm /var/lib/dpkg/lock-frontend       

sudo rm /var/lib/dpkg/lock
```