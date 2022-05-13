import math
# count = [0, 1]
ToH4_arr = ['']  # This is the array where we will be storing solved subproblems.
# It is first initialized by an empty string as the solution to problem of disk 0 is nothing (empty string)
flag = 0  # This flag is used to determine if second recursive call ToH4(n - 2, c, b, a, d) is called.
# If so, flag will be equal 1
current_disk_no = 0  # This parameter will be used to correctly print out disk number in ToH3
# to solve the 4 peg problem optimally
found = [0]  # This is an array that determines whether a particular ToH4 was found already
# for i in range(2, 100):
#     count.append(-1)

for i in range(1, 100):  # This loop is used only to initialize the arrays above with empty / 0
    ToH4_arr.append("")
    found.append(0)


def main():
    global ToH4_arr
    n = 8
    #  uncomment this line if you want to test with other values of n
    #  n = int(input('Enter number of disks: '))
    print("---------------Solution using Dynamic Programming--------------")
    ToH4(n, 'A', 'B', 'C', 'D')
    print(ToH4_arr[n])
    print("-----------------Optimal Solution------------------------------")
    ToH43(1, n, 'A', 'B', 'C', 'D')
    # #uncomment this loop to see the subproblems
    # being stored and memory(array) being used
    # for i in range(0, n+1):
    #   print(ToH4_arr[i])


def ToH3(m, p, q, r):
    if m == 1:
        print(f"Move disk {current_disk_no} from rod {p} to rod {q}")
        return

    ToH3(m - 1, p, r, q)

    print(f"Move disk {m+ current_disk_no -1} from rod {p} to rod {q}")

    ToH3(m - 1, r, q, p)


def ToH4(n, a, b, c, d):  # Solving ToH4 using dynamic programming but not the most optimal solution
    global flag
    global ToH4_arr
    if flag == 1:  # Checks if second recursive call was called
        if n == 0:  # Checks base condition and returns empty string
            # because it's the solution to ToH4 of 0 disks
            return ToH4_arr[0]
        elif n == 1:    # Checks base condition and returns solution
            # to ToH4 of 1 disk with is simply moving disk 1 1 move
            ToH4_arr[1] = f"Move disk 1 from rod {a} to rod {b}\n"
            return ToH4_arr[1]
        elif ToH4_arr[n] != '' and found[n] == 1:
            return ToH4_arr[n]
        else:
            ToH4_arr[n] = ToH4(n - 2, a, c, d,
                               b) + f"Move disk {n - 1} from rod {a} to rod {d} \n" + f"Move disk {n} from rod {a} to rod {b} \n" + f"Move disk {n - 1} from rod {d} to rod {b} \n"
            ToH4_arr[n] += ToH4(n - 2, c, b, a, d)
            flag = 1
            return ToH4_arr[n]
    if n == 0:  # Enters only if Second recursive hasn't been called yet
        # Checks base condition and returns empty string
        # because it's the solution to ToH4 of 0 disks
        return ToH4_arr[0]
    elif n == 1:
        # Checks base condition and returns solution
        # to ToH4 of 1 disk with is simply moving disk 1 1 move
        ToH4_arr[1] = f"Move disk 1 from rod {a} to rod {b}\n"
        return ToH4_arr[1]
    elif ToH4_arr[n] != '':  # Checks if problem was solved before; if so, it gets it returns
        # the solution calculated before
        return ToH4_arr[n]
    else:  # else it calculates the problem as it has not been solves yet
        # and then stores it in ToH_arr of index n
        ToH4_arr[n] = ToH4(n-2, a, c, d, b) + f"Move disk {n-1} from rod {a} to rod {d} \n" + f"Move disk {n} from rod {a} to rod {b} \n" + f"Move disk {n-1} from rod {d} to rod {b} \n"
        ToH4_arr[n] += ToH4(n-2, c, b, a, d)
        flag = 1  # turns flag = 1 as the second recursive call was just called
        return ToH4_arr[n]


def ToH43(i, j, a, b, c, d):        # The most optimal method developed first by Stockmeyer using k=sqrt(2m)
    global ToH4_arr
    global current_disk_no
    m = j - i + 1  # First we store the largest disk number we have
    k = math.floor(math.sqrt(2*m))  # Equation to get optimal k was derived from Frame–Stewart Optimal Algorithm
    #  k is the largest disks to be left at A and solved by ToH3

    ToH4(m - k, a, d, b, c)  # Smallest disks above k (m - k disks) are first moved to peg D
    print(ToH4_arr[m - k])
    current_disk_no = m-k+1  # current_disk_no is set to correctly print out k disk numbers
    # being moved to B
    ToH3(k, a, b, c)  # Moves k largest disks without using peg D thus
    # transforming the problem to ToH3 instead of ToH4
    print("")
    ToH4(m - k, d, b, a, c)  # Moves smallest disks on peg D to peg B
    print(ToH4_arr[m - k])


if __name__ == '__main__':
    main()

