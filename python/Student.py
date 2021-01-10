class Student(object):
    """docstring for Student"""

    def __init__(self, name, score):
        super(Student, self).__init__()
        self.name, self.score = name, score

    def print_score(self):
        print('%s:%s' % (self.name, self.score))


bart = Student('Bart Simpson', 59)
bart.print_score()
