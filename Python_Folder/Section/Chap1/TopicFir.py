import numpy as np
def main():
    sum = 0
    n = int(input('n = '))
    for x in range(n) :
        sum += x + 1
    print("The sum obtained by the for loop: ")
    print(sum)
    sum = np.sum(range(1, n + 1))
    print("The sum obtained by looping through the sum function: ")
    print(sum)
if __name__ == '__main__':
    main()
