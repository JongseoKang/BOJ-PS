lst = [0] * 20000
for i in range(1, 10001):
    lst[i + (int)(i / 10000) + (int)(i % 10000 / 1000) + (int)(i % 1000 / 100) + (int)(i % 100 / 10) + i % 10] = 1
for i in range(1, 10001):
    print((str(i) + '\n') * ((lst[i] + 1) % 2), end='')