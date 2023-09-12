pwd = "1234" # NONONO
print(pwd)

FILE_NAME = "/Users/nicklin/Desktop/cpp/cpp_lesson/2023-09-12/.password"

f = open(FILE_NAME)
pwd_from_file = f.read()
f.close()
print(pwd_from_file)


with open(FILE_NAME) as f:
    password = f.read()
    # blabalbal

print(password)
