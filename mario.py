from cs50 import get_string, get_int

while True:
    answer = get_int("Height: ")
    if answer > 0 and answer < 9:
        break

for j in range(1, answer + 1):
    print(" " * (answer - j), end="")
    print("#" * j, end="")
    print("  ", end="")
    print("#" * j)
