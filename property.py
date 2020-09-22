class Student(object):

    def get_score(self):
        return self._score

    def set_score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must be an integer!')
        self._score = value


s = Student()
print(s.set_score(60))
print(s.get_score())
print(s.set_score(9999))
