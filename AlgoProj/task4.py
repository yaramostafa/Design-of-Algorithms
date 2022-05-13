if __name__ == "__main__":
    # asking user to input coins in the leftmost box to process
    initCoins = int(input("Enter Coins: "))

    # resultArr is the array where we will save our final distribution
    # resultArr will change each iteration to reflect new distributions
    resultArr = [initCoins]
    print(resultArr)
    ind = 0

    # checking whether there still an element not equal to 0 or 1
    while resultArr[ind] > 1:
        # Add a zero to right of the element to increment it later
        resultArr.append(0)

        # Here comes the greedy concept
        # loop fetches the element with value > 1
        # the element with value > 1 is considered the local region
        while resultArr[ind] > 1:
            # deducting 2 coins from current box
            resultArr[ind] -= 2
            # adding 1 coin to the next right boxx
            resultArr[ind + 1] += 1

            # show coin distribution each time
            print(resultArr)
        # the local region is solved completely, now we can move to the next local region (element)
        ind += 1




