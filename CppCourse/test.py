# if n is odd a(n) = (n+1)/2 = n/2+1/2,

# if n is even a(n)=(n-2)/2 =n/2–1.

# 1-0-2-1-3-2-4-3-5-4
result = 0
for i in range(1,15):
    if i % 2 == 0:
        result = i/2-1
    else:
        result = i / 2 + 1/2
    print(result)