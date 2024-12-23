from cs50 import get_int

x = get_int("What is the x=> ")
y = get_int("What is the y=> ")

if x>y:
    print("x is bigger than y.")

elif y>x :
    print("y is bigger than x.")

else:
    print("x is equal to y.")