a = [1,2,3]

try:
    print(a[6])
    print("end of try")
except Exception as e:
    print(e)
    print("something wrong")

print("end of program")
