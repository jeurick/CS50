from cs50 import get_float

# assign variables to US coin equivalent and create variable for coins to increment
quarter = 25
dime = 10
nickel = 5
penny = 1
coins = 0

dollars = get_float("Change owed: ")  # prompt for input
while dollars < 0:
    dollars = get_float("Change owed: ")  # reprompt if entry invalid
cents = round(dollars * 100)  # round dollars to 100

while cents >= quarter:
    cents -= quarter
    coins += 1

while cents >= dime:
    cents -= dime
    coins += 1

while cents >= nickel:
    cents -= nickel
    coins += 1

while cents >= penny:
    cents -= penny
    coins += 1

print(f"{coins}")

