def yazdir(n):
    if n==0:
        return
  
    yazdir(n-1)

    for i in range(n):
        print("#", end='')

    print("")    

while True:
    x = int(input("What is the height ? "))
    if x>0:
        break

yazdir(x)

