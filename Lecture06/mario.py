def yazdir(n):
    if n==0:
        return
  
    yazdir(n-1)
    print("?" *n)
   

      
def get_int():
    try:
        x = int(input("What is the height ? "))
        if x>0:
            return x
    except ValueError :
        print("It is not an integer.")        

yazdir(get_int())


