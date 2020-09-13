import os
list(range(1, 11))
L = []
for x in range(1, 11):
    L.append(x*x)

print(L)

a = [x*x for x in range(1, 11)]
print(a)

a = [m+n for m in 'ABC' for n in 'XYZ']
print(a)

# 输出目录下文件
directory = [d for d in os.listdir('.')]
print(directory)
