import math

global i
i = 0
arr = []


def recursiveCoin(arr,i,lenArr):

    if i == lenArr:
        return
    if arr[i] <= 1:
        i += 1
    else:

        arr[i] -= 2
        if arr[i] > 1 and arr[i+1] is None:
            arr.append(0)
        arr[i+1] += 1
        print(arr)

    recursiveCoin(arr, i,lenArr)


if __name__ == "__main__":
    coinVal = int(input("Enter value: "))
    lenArr = math.ceil(math.log2(coinVal))
    arr.append(coinVal)

    recursiveCoin(arr,i, lenArr)





    # initCoins = int(input("Enter the coins: "))
    # noOfBits = math.ceil(math.log2(initCoins))
    # #print(noOfBits)
    # denomresultArr = [pow(2,x) for x in range(noOfBits)]  #[4,2,1]
    # coinDistributionSet = [0] * len(denomresultArr)
    #
    # while initCoins > 0:
    #     for temp in denomresultArr[::-1]: #4,2,1
    #         if initCoins >= temp:
    #             break
    #     initCoins -= temp # 3
    #     coinDistributionSet[denomresultArr.index(temp)] += 1
    #
    # print(coinDistributionSet[::-1])

    # Driver Code






