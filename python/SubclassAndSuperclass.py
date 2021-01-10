class Animal(object):
    """My class"""

    def run(self):
        print('Animal is running...')

    def run_twice(self):
        print('Animal is running...')
        print('Animal is running...')


class Dog(Animal):

    def run(self):
        print('Dog is running...')

    def eat(self):
        print('Eating meat...')


class Cat(Animal):

    def run(self):
        print('Cat is running...')


animal = Animal()
dog = Dog()
dog.run()
dog.eat()
cat = Cat()
animal.run_twice()

# 判定是否为某类别
print(isinstance(dog, Dog))
print(isinstance(cat, Cat))
