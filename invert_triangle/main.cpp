#include <iostream>
#include<math.h>

using namespace std;
//first function in case of even base of coins
void even_reverse(int n){
    int steps=0;
    char tri[n+2][2*n-1];
    //intializ the matrix
     for(int i=0;i<n+2;i++){
       for(int j=0;j<2*n-1;j++){
       tri[i][j]='+';
       }
    }
    int fillin=0;
    int fill2=0;
    //draw the triangle
    for(int i=n;i>=0;i--){
       for(int j=fillin;j<2*n-fill2-1;j+=2){
       tri[i][j]='O';
       }
       fillin++;
       fill2++;
    }
   /////////////////////////////////////////////////////
   //print the actual triangle
    cout<<"triangle before reversing :"<<endl;
    for(int i=0;i<n+2;i++){
       for(int j=0;j<2*n-1;j++){
        cout<<tri[i][j];
       }
       cout<<endl;
    }
    cout<<endl;
    //////////////////////////////////////////////////////
    //swap the apex to start reversing the triangle==> step 1
    tri[1][(2*n-1)/2]='+';
    tri[n+1][(2*n-1)/2]='O';
    steps++;
    //print the triangle
    cout<<"triangle after step : " ;
    cout<< steps <<endl;
     for(int i=0;i<n+2;i++){
       for(int j=0;j<2*n-1;j++){
        cout<<tri[i][j];
       }
       cout<<endl;
    }
    /////////////////////////////////////////////////////
    /*
    the following loop does the following:
    1. calculate the no. of coins that needs to be swapped in each row
    2. slide the coins to it's new place
    */
    int o=2; //variable that indicates the supposed no. of coins in the current row
   for(int i=n;i>0;i--){
        int nO=0;
        int place=-1;
        //indicate the place of the first coin that would be moved
        for(int j=0;j<2*n-1;j++){
            if(tri[i][j]=='O'){
                nO++;
                if(place == -1){
                    place=j;
                }
            }

        }
        /////////////////////////////////////////////////
        while(nO>o){
            //case 1: there is a coin between the target coin and it's new place
            // coins would slide one by one till reaching it's correct new place
            if(tri[i-2][place]=='O'){
                    int x=i-2;
                while(tri[x-2][place]=='O'){
                    x=x-2;
                }
                //left part of the triangle
                tri[2+n-i][place]='O';
                tri[x][place]='+';
                 steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }

                for(int k= x;k<i;k+=2){
                    tri[k][place]='O';
                    tri[k+2][place]='+';
                    steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }
                        //right part of the triangle
                        tri[2+n-i][2*n-place-2]='O';
                      tri[x][2*n-place-2]='+';
                       steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }
                     for(int k=x;k<i;k+=2){
                    tri[k][2*n-place-2]='O';
                    tri[k+2][2*n-place-2]='+';
                    steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }

                }

            }

            nO-=2;
            } ////////////////////////////////////////////////
            else
            {
            //case 2: the coin can be directly slipped
            tri[2+n-i][place]='O';
            tri[i][place]='+';
            steps++;
               cout<<"triangle after step : " ;
            cout<< steps <<endl;
         for(int i=0;i<n+2;i++){
            for(int j=0;j<2*n-1;j++){
             cout<<tri[i][j];
            }
        cout<<endl;
            }
            tri[2+n-i][2*n-place-2]='O';

            tri[i][2*n-place-2]='+';
            nO-=2;
            steps++;
            cout<<"triangle after step : " ;
            cout<< steps <<endl;
         for(int i=0;i<n+2;i++){
            for(int j=0;j<2*n-1;j++){
             cout<<tri[i][j];
            }
        cout<<endl;
            }
        }


        place+=2;
    }


    o++;
   }



}
/////////////////////////////////////////////////
// in case of odd base of coins
void odd_reverse(int n){
     int steps=0;
    char tri[n+2][2*n-1];
     for(int i=0;i<n+2;i++){
       for(int j=0;j<2*n-1;j++){
       tri[i][j]='+';
       }
    }
    int fillin=0;
    int fill2=0;
    for(int i=n;i>=0;i--){
       for(int j=fillin;j<2*n-fill2-1;j+=2){
       tri[i][j]='O';
       }
       fillin++;
       fill2++;
    }

    cout<<"triangle before reversing :"<<endl;
    for(int i=0;i<n+2;i++){
       for(int j=0;j<2*n-1;j++){
        cout<<tri[i][j];
       }
       cout<<endl;
    }
    cout<<endl;

    int o=1;
   for(int i=n+1;i>0;i--){
        int nO=0;
        int place=-1;
        for(int j=0;j<2*n-1;j++){
            if(tri[i][j]=='O'){
                nO++;
                if(place == -1){
                    place=j;
                }
            }

        }
        /////////////////////////////////////////////////////////
        while(nO>o){
        if(tri[i-2][place]=='O'){
                int x=i-2;
                while(tri[x-2][place]=='O'){
                    x=x-2;
                }
                tri[1+n-i][place]='O';
                tri[x][place]='+';
                 steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }
                for(int k= x;k<i;k+=2){
                    tri[k][place]='O';
                    tri[k+2][place]='+';
                    steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }
                        tri[1+n-i][2*n-place-2]='O';
                      tri[x][2*n-place-2]='+';
                       steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }
                     for(int k=x;k<i;k+=2){
                    tri[k][2*n-place-2]='O';
                    tri[k+2][2*n-place-2]='+';
                    steps++;
                    cout<<"triangle after step : " ;
                    cout<< steps <<endl;
                     for(int i=0;i<n+2;i++){
                        for(int j=0;j<2*n-1;j++){
                         cout<<tri[i][j];
                        }
                    cout<<endl;
                        }

                }

            }

            nO-=2;
        }
        ///////////////////////////////////////////////////
        else{
              tri[1+n-i][place]='O';
            tri[i][place]='+';
            steps++;
               cout<<"triangle after step : " ;
            cout<< steps <<endl;
         for(int i=0;i<n+2;i++){
            for(int j=0;j<2*n-1;j++){
             cout<<tri[i][j];
            }
        cout<<endl;
            }
            tri[1+n-i][2*n-place-2]='O';

            tri[i][2*n-place-2]='+';
            nO-=2;
            steps++;
            cout<<"triangle after step : " ;
            cout<< steps <<endl;
         for(int i=0;i<n+2;i++){
            for(int j=0;j<2*n-1;j++){
             cout<<tri[i][j];
            }
        cout<<endl;
            }
        }

            place+=2;
        }


    o++;
   }

}

int main()
{
    int n;
    cin>>n;
    if(n<0){
        cout<<"invalid no. of coins";
        return -1;
    }

    if(n%2==0){
        even_reverse(n);
    }else{
        odd_reverse(n);
    }

    return 0;
}
