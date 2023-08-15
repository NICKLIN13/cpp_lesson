# import datetime
# print(datetime.datetime.now())

# dict (map key-value pair)
# list (vector)

# mydict = dict()
# mydict = {'a': 1, 'b': 2, 'c': 3}

# print("b = ")
# print(mydict["b"])

# person1 = dict()
# person1["name"] = "Nick"
# person1["phone"] = 123456
# print(person1)

# # print("The name is ", person1["name"], ".")
# # printf("num1 = %d, num2 = %d", num1, num2)
# # print("The name is {}.".format(person1["name"]))
# print(f"The name is {person1['name']}.")


# andrew = dict()
# andrew["name"] = "Andrew"
# andrew["phone"] = 789456
# print(andrew)

# print(f"{andrew['name'] = }")

# # OOP: class c++ python java c#

# class_A = dict()
# class_A = {1: person1,
#            2: andrew
#            }

# print(f"{class_A[2] = }")
# print(f"{class_A = }")

# print(f"{dict = }")
# print(f"{class_A = }")

import dataclasses


class Person:
    def __init__(self, name, number) -> None:
        self.name = name
        self.number = number


@dataclasses.dataclass
class Person2:
    name: str
    number: int
# print("123")



nick = Person2(name="Nick", number=123456)
print(nick)
print(f"{nick.name = }")
print(f"{nick.number = }")

print(f"{nick = }")

andrew = Person2(name="Andrew", number=574966)
print(f"{andrew = }")
print(f"{dataclasses.asdict(andrew) = }")




andrew2 = dict()
andrew2["name"] = "Andrew"
andrew2["phone"] = "asldflasdf"

import json

json_str = json.dumps(andrew2)
print(f"{json_str = }")
print(f"{type(json_str) = }")

json_dict = json.loads(json_str)
print(f"{json_dict = }")
print(f"{type(json_dict) = }")
