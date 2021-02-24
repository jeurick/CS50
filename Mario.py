l = (input("Height: "))  # prompt for height
while not l.isdigit() or int(l) > 8 or int(l) < 1:  # reprompt if entry invalid
    l = (input("Height: "))

for i in range(int(l)):  # loop for height
    if (int(l) - i) - 1 != 0:  # ask if spaces are necessary
        print(" " * ((int(l) - i) - 2), "#" * (i + 1))  # if so print appropriate spaces and hashes
    else:
        print("#" * int(l))  # else only print hashes
