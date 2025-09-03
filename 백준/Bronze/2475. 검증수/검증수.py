numbers = list(map(int, input().split()))

total = sum(n**2 for n in numbers)
print(total % 10)
