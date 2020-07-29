from cs50 import get_float

while True:
    answer = get_float("Change owed: ")
    if answer >= 0:
        break

X = int(answer/0.25)
R = (answer - (0.25 * X))
A = round(R, 2)

S = int(A/0.1)
T = (A - (0.1 * S))
B = round(T, 2)

U = int(B/0.05)
V = (B - (0.05 * U))
C = round(V, 2)

W = int(C/0.01)
Y = (C - (0.01 * W))
D = round(Y, 2)

print(X + S + U + W)