def main():
    string = input("String: ").strip().split()
    print(algorithm(string))


def algorithm(string):
    letters = 0
    words = len(string) 
    sentences = 0 
    lookings = [".", "?", "!"]


    for word in string:
        for i in range(len(word)):
            if word[i].isalpha():
                letters += 1
            elif word[i] in lookings:
                sentences += 1

    L = letters/words * 100
    S = 100/(words/sentences)

    result = 0.0588 * L - 0.296 * S - 15.8
    result = round(result)

    if result < 1:
        return("Before Grade 1")
    elif result > 16:
        return("Grade 16+")
    else:
        return(f"Grade {result}")
    
if __name__ == "__main__":
    main()
