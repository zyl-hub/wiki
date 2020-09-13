import math
# help(abs)


def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x


b = my_abs(-2)
# raise error
# my_abs('a')
print(b)

# none function


def nop():
    pass

# 返回一个tuple


def move(x, y, step, angle=0):
    nx = x+step*math.cos(angle)
    ny = y+step*math.sin(angle)
    return nx, ny


print(move(12, 12, 1, math.pi/6))


def power(x, n):
    s = 1
    while n > 0:
        n = n-1
        s = s*x
    return s
