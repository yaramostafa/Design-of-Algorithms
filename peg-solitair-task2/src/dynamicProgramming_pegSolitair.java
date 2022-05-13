import java.util.ArrayList;
import java.util.*;

class gameSolitaire
{

    class TheMovement  // instead of struct to format coordinates for the movement
    {
        int from;
        int middle;
        int to;
        TheMovement(int from, int middle, int to)
        {
            this.from = from;
            this.middle = middle;
            this.to = to;
        }
        public String toString()
        {
            return("(from :" + this.from + ", Middle " + this.middle + ", to " + this.to + " )");
        }


    }

    ArrayList<Integer> myBoard; // this will contains my main board
    ArrayList<TheMovement> movementList; // to store the path of movement on it
    ArrayList<ArrayList<Integer>> unsuccessfulPatterns; // stores the unsuccessful patterns later
    int numberofbits;// input by the user and checked in the main function to make sure it is evenNumber > 2



    gameSolitaire(ArrayList<Integer> myBoard, int numberofbits)   //----------------constructor
    {
        this.myBoard = myBoard;
        movementList = new ArrayList<>();
        unsuccessfulPatterns = new ArrayList<>();
        this.numberofbits = numberofbits;
    }
    private void printOutput() // print the successful path of the output
    {
        for(TheMovement theMovement : movementList)
        {
            System.out.println(theMovement.toString());
        }
    }
    private void displayBoard()
    {
         for(Integer i: myBoard)
         {
                 System.out.print(Integer.toString(i) + " ");


         }
        System.out.println();
    }
    private int getCount()      // count the number of remaining ones in the board
    {
        int count =0;
        for(int i = 0; i < myBoard.size() ; i++)
        {
            if(myBoard.get(i) == 1)
            {
                count++;
            }
        }
        return count;
    }
    private void MoveOrder(TheMovement theMovement)  // make a new move and stored it into the movementList
    {                                                // and change the pattern in the board from 110 to 001
        myBoard.set(theMovement.from,0);
        myBoard.set(theMovement.middle,0);
        myBoard.set(theMovement.to,1);
        movementList.add(theMovement);
    }
    private void undoMoveOrder(TheMovement theMovement) // undo the last move as it will not lead to sucsessful path
    {                                                      //and return the pattern to its origin 110
        myBoard.set(theMovement.from,1);
        myBoard.set(theMovement.middle,1);
        myBoard.set(theMovement.to,0);
        movementList.remove(movementList.size()-1); // to remove the last value added
    }
    private ArrayList getAvailableMoves() // this function is responsible for getting (all) the valid moves that
    {                                       // can be done in this call then store them in arraylist
        ArrayList<TheMovement> availableMoves = new ArrayList<>();
        for(int i = 0; i < myBoard.size(); i++)
        {
            if (myBoard.get(i) == 0)// iterate until find a hole
            {
                if(i-2 >=0){
                    if(myBoard.get(i-2) ==1 && myBoard.get(i-1) ==1 ) // check for 110 pattern from right to left
                    {
                        availableMoves.add(new TheMovement((i-2),(i-1),i));
                    }
                }

                if(i+2 <= numberofbits-1)
                {
                    if(myBoard.get(i+2) ==1 && myBoard.get(i+1) ==1 )// check for 110 pattern from left to right
                    {
                        availableMoves.add(new TheMovement((i+2),(i+1),i));
                    }
                }
            }
        }
        return availableMoves;
    }

    private ArrayList<Integer> copyArrayList(ArrayList<Integer> input) // copy arrayList into another
    {                                                                // used later to update the unsuccessful patterns arraylist
        ArrayList<Integer> newGrid = new ArrayList<>();

        for(Integer i : input)
        {
            newGrid.add(Integer.valueOf(i));
        }
        return newGrid;
    }
    public boolean checkSolution() // this is the core method
    {
        if(unsuccessfulPatterns.contains(myBoard)) // check if the current pattern matches one of the
        {                                               //unsuccessful patterns stored
            return false;
        }

        if(getCount() == 1)       //if there is one 1 remaining peg then it is solvable
        {
            displayBoard();
            printOutput();
            return true;
        }
        else//if there are more than 1 peg
        {
           ArrayList<TheMovement> theMovements = getAvailableMoves();


           for(TheMovement theMovement : theMovements)
           {
               MoveOrder(theMovement);
               if (checkSolution())//recursive calls done to check if it will end
               {                    //with successful path checkSolution will return true

                   return true;
               }
               else
               {
                undoMoveOrder(theMovement); // here when it is unsuccessful we will undo our moves to try other one
               }
           }


        }

        if(!unsuccessfulPatterns.contains(myBoard))// if the faild path not in the unsuccessful arrayList
        {                                               // then add it

            unsuccessfulPatterns.add(copyArrayList(myBoard));
        }

        return false;

    }

}






public class dynamicProgramming_pegSolitair {
    public static void main(String[] args) {
        ArrayList<Integer> grid = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        int numberofbits = in.nextInt();

        if(numberofbits %2 ==0 && numberofbits >2 ) {
            for (int i = 0; i < numberofbits; i++) {
                grid.add(in.nextInt());
            }


            if (new gameSolitaire(grid, numberofbits).checkSolution() == false){
                System.out.println(grid);
                System.out.println("unsolved");}
        }
        else System.out.println("number must be even > 2");




    }
}