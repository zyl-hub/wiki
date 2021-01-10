d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
print(d['Michael'])

d['Adam'] = 67
d['Jack'] = 88
print(d['Jack'])
d['Jack'] = 90
print(d['Jack'])

var = 'Thomas' in d

d.get('Thomas')
d.get('Thomas', -1)

d.pop('Bob')
print(d)

# set 集合中的元素不能重复
s = set([1, 2, 3])
print(s)
s.remove(3)
print(s)

s1 = set([2, 3, 4])
# 交
print(s & s1)
# 并
print(s | s1)

a = 'abc'
# 会创建一个新的字符串
a.replace('a', 'A')
