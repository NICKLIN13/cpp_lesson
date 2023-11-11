import math
print(math.sqrt(123))
print(math.sqrt(100))


import pandas

students = pandas.DataFrame(
    [
        ["A", 13, 3],
        ['B', 15, 7],
        ['C', 17, 8]
    ]
)
students.columns = ['name', 'age', 'class']
print(students["age"])

students.to_csv("/Users/andrewchiu/Documents/Tutor/NICK_algo/2023-08-01/students.csv")

"""

students
name age class
A    13   5
B    15   4
C    13   3

students["age"] == [13, 15, 13]
students["name"] == [A,B,C]
"""