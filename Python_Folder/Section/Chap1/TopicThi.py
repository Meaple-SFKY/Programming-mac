def isPrime(temp):
    if temp == 1:
        return False
    elif temp == 2:
        return True
    else:
        for i in range(2, temp):
            if temp % i == 0:
                return False
        return True

def formTable(top):
    primeTable = []
    for i in range(1, top):
        if isPrime(i) == True:
            primeTable.append(i)
    return primeTable

def isPrimed(temp):
    primeTable = formTable(temp)
    for i in primeTable:
        for j in primeTable:
            if i + j == temp:
                print(i, " + ", j, " = ", end = "")
                return True
    return False

def main():
    bottom = 6
    top = 200
    for temp in range(bottom, top + 1):
        if (temp % 2 == 0):
            if isPrimed(temp):
                print(temp)
            else:
                print(temp, " cannot be split into two prime numbers")
if __name__ == "__main__":
    main()