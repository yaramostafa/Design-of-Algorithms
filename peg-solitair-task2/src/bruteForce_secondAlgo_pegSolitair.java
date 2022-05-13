public class bruteForce_secondAlgo_pegSolitair {
    boolean flag = true;

    void printarray(int arr[], int size) {

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i]);

        }
        System.out.println();
    }

    void checksol(int arr[], int n, int size) {
        while (flag == true) {
            int counter = 0;


            if (n == 1) {

                return;
            }

            while (arr[counter] == 0)
                counter++;

            for (int i = counter; i < size - 2; i++) {
                if (arr[i] == 0 && arr[i + 1] == 1 && arr[i + 2] == 1) {
                    arr[i] = 1;
                    arr[i + 1] = 0;
                    arr[i + 2] = 0;
                    n--;
                    printarray(arr, size);
                    flag = true;
                    break;

                }
                else if (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 0) {
                    arr[i] = 0;
                    arr[i + 1] = 0;
                    arr[i + 2] = 1;
                    n--;
                    printarray(arr, size);
                    flag = true;
                    break;

                }
                else {
                    flag = false;
                }
            }
        }

        if (flag == false)
        {
            System.out.println("unsolvable");
        }


    }
}
