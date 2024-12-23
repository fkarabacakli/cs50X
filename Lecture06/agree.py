
s = input("Do you agree ? ")

s = s.lower()

if s == "yes" or s == "y":
    print("Agreed")
elif s in ["no","n"]:
    print("Did not agree")
else :
    print("Uncorrect usage.")        