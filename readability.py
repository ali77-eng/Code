from cs50 import get_string, get_string, get_float
import array as arr

string = get_string("Text: ")
letters = 0
for i in string:
    if (i.isalpha() == True):
        letters+=1
words = 1;
for j in string:
    if (j.isspace() == True):
        words+=1
sentences = 0
sentences = string.count('.') + string.count('!') + string.count('?')
L = (100*letters)/words
S = (100*sentences)/words
C = 0.0588*L - 0.296*S - 15.8
index = round(C)
if (C >= 16):
    print("Grade 16+")
elif (1 < C and C < 16):
    print("Grade", index)
elif (C < 1):
    print("Before Grade 1")