d = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
for i in d:
    print(d[i])

for i in 'ABC':
    print(i)
# Python内置的enumerate函数可以把一个list变成索引-元素对，这样就可以在for循环中同时迭代索引和元素本身：
for i, value in enumerate(['A', 'B', 'C']):
    print(i, value)

L = list(range(100))


def findMaxAndMin(L):
    if not isinstance(L, (list)):
        raise TypeError('bad operand type')
    min = L[0]
    max = L[0]
    for i in range(len(L)):
        if(L[i] > max):
            max = L[i]
        if(L[i] < min):
            min = L[i]
    return min, max


# test raise error
# L = (1, 2, 3)
print(findMaxAndMin(L))
