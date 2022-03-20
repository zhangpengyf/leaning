message = "one of python's strengths is its diverse community."
print(message)

age = 23
message = "Happy " + str(age) + "rd Birthday!"

print(message)

n = 8
message = "My favorite number is " + str(n) + "!"

print(message)
numbers = list(range(1,6))
print(numbers)

even_numbers = list(range(2,11,2))
print(even_numbers)

squares = []
for value in range(1,11):
	square = value**2
	squares.append(square)
	
print(squares)

squares = []
for value in range(1,11):
	squares.append(value**2)

print(squares)
squares = [value**2 for value in range (1,11)]
print(squares)

for value in range(1,5):
	print(value)

numbers = list(range(1,6))
print(numbers)


squares = []
for value in range(1,11):
	square = value**3
	squares.append(square)
print(squares)

squares = []
for value in range(1,11):
	squares.append(value**3)
print(squares)




numbers = list(range(1,101))
if min(numbers) == 1:
	print("shi concg 1 kaishi de ")
if max(numbers) == 99:
	print("shi concg 101 kaishi de ")

numbers = list(range(1,100000001))
n = 0
for value in numbers:
	n = n+value


print(n)
