tests = int(input())
for i in range(tests):
    cant_one = input().count('1')
    if cant_one == 0:
        print(0) ; continue
    print(cant_one)