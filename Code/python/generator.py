# 把一个列表生成式的[]改成()，就创建了一个generator：
g = (x*x for x in range(10))
print(g)
# for i in range(10):
# print(next(g))

for n in g:
    print(n)


def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        a, b = b, a+b
        n = n+1
    return 'done'


print(fib(6))


def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a+b
        n = n+1
    return 'done'


f = fib(6)
print(f)

g = fib(6)
while True:
    try:
        x = next(g)
        print('g:', x)
    except StopIteration as e:
        print('Generator return value:', e.value)
        break
