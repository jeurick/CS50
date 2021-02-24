from cs50 import get_string

text = get_string("Text: ")
j = 0.0
q = 0.0
w = 1.0
for i in range(len(text)):
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        j += 1.0
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        q += 1.0
    if text[i] == ' ':
        w += 1.0

j = ((j / w) * 100.0)
q = ((q / w) * 100.0)
index = round(0.0588 * j - 0.296 * q - 15.8)

if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade: {index}")
