from cs50 import get_int
from sys import exit

def main():
    card_number = str(get_int("Card ID: "))
    if valid_card(card_number):
        if card_number.startswith():
            pass

def valid_card(card_number):
    
    lenght = len(card_number)
    valid_length = [13, 15, 16]
    if lenght not in valid_length:
        exit("Invalid Card ID")

    if lenght%2 == 0:
        çift = True
    else:
        çift = False
    
    first = []
    second = []

    if çift:
        
        cursor = lenght-2
        
        while cursor >= 0:
            number = int(card_number[cursor])*2
            if number >10:
                first.append(int(number/10))
                first.append(number%10)
            else:
                first.append(number)
            
            second.append(int(card_number[cursor+1]))
            cursor -= 2
    else:
        cursor = lenght-1
        while cursor >= 0 :
            if cursor==0:
                second.append(int(card_number[cursor]))
                cursor -= 2
            else:
                number = int(card_number[cursor-1])*2
                if number >10:
                    
                    first.append(int(number/10))
                    first.append(number%10)
                else:
                    first.append(number)

                second.append(int(card_number[cursor]))
                cursor -= 2
    first = sum(first) + sum(second)
    if first %10 == 0:
        return True
    else:
        return False      
    
if __name__ == "__main__":
    main()