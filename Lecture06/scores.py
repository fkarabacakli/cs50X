from cs50 import get_int
scores = [72, 73, 33]

count = get_int("How many score do you want to add? ")

for _ in range(count):
    answer = get_int("Score: ")
    scores.append(answer)


avarage = int(sum(scores) / len(scores))
print(avarage)