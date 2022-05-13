#include <stdio.h>
#include<stdlib.h>

/**************************IF YOU NEED TO CHANGE THE INPUT SIZE ************************************/
//IF YOU NEED TO CHANGE THE INPUT: 1- change the number RowSwitchNum
//                                 2- add inputs in RowSwitches array
//                                 3- if the number is very large you can increase MovingSequencesNum

#define RowSwitchNum (6) //Number of switches in the array

int RowSwitches[RowSwitchNum]={1,1,1,1,1,1};

#define TotalSwitch_Num (RowSwitchNum+1)        //number of indices of first dimension array
#define MovingSequencesNum (TotalSwitch_Num*330) //number of indices of second dimension array

/**************************IF YOU NEED TO CHANGE THE INPUT SIZE ************************************/



int  CurrentSwitch_movingSequence[TotalSwitch_Num][MovingSequencesNum];
int StartIndex1D_LeftSideArray=1;
int EndIndex1D_RightsideArray=TotalSwitch_Num;
#define   size ( EndIndex1D_RightsideArray-StartIndex1D_LeftSideArray+1)
int TotalBasicOperation=0;


void printArray_1D(int RowArray[],int startIndex, int EndIndex){

    for(int m=startIndex; m<=EndIndex;m++){
      printf("%d",RowArray[m]);
    }
    printf("\n");
}

void printArray_2D(void){

	for(int CurrentIndex_1D=TotalSwitch_Num-1; CurrentIndex_1D>=1; CurrentIndex_1D--){
		printf("%d",CurrentIndex_1D);
		printf("  ");
		for(int CurrentIndex_2D=0;CurrentIndex_2D<MovingSequencesNum;CurrentIndex_2D++){
			printf("%d",CurrentSwitch_movingSequence[CurrentIndex_1D][CurrentIndex_2D]);
		}
		printf("\n");
	}

}


int Get_LastIndexNotEqualZero(int CurrentIndex_1D,int EndIndex_2D){
	int CurrentIndex_2D=EndIndex_2D-1;
	for(;CurrentIndex_2D>=0; CurrentIndex_2D-- ){
		if(0 != CurrentSwitch_movingSequence[CurrentIndex_1D][CurrentIndex_2D] )
			return CurrentIndex_2D;
	}
	return CurrentIndex_2D;
}

//TotalRecursiveCallsNum will be equal to the TotalSwitch_Num
void GetMovingSequence_DivConquer(int TotalRecursiveCallsNum){

	if(TotalRecursiveCallsNum == 0){
		return;
	}

	else if (TotalRecursiveCallsNum == RowSwitchNum){
		CurrentSwitch_movingSequence[TotalSwitch_Num-1][0]=TotalRecursiveCallsNum;
		TotalRecursiveCallsNum--;
	}

	else if (TotalRecursiveCallsNum == RowSwitchNum-1){

			CurrentSwitch_movingSequence[TotalSwitch_Num-2][0]=TotalRecursiveCallsNum;
			TotalRecursiveCallsNum--;
		}

	else if( (TotalRecursiveCallsNum>0) && (TotalRecursiveCallsNum<TotalSwitch_Num-2)){

		int start=TotalRecursiveCallsNum+2;
		int CurrentIndex_2D=0;
		for( ; start<=RowSwitchNum;start++){
			int LastIndexNotEqualZero_2D=Get_LastIndexNotEqualZero(start, MovingSequencesNum );
			for(;LastIndexNotEqualZero_2D>=0;LastIndexNotEqualZero_2D--){
				CurrentSwitch_movingSequence[TotalRecursiveCallsNum][CurrentIndex_2D]=CurrentSwitch_movingSequence[start][LastIndexNotEqualZero_2D];
				CurrentIndex_2D++;
			}

		}

		CurrentSwitch_movingSequence[TotalRecursiveCallsNum][CurrentIndex_2D]=TotalRecursiveCallsNum;

		for(int i =CurrentIndex_2D-1;i>=0;i--){
			CurrentIndex_2D++;
			CurrentSwitch_movingSequence[TotalRecursiveCallsNum][CurrentIndex_2D]=CurrentSwitch_movingSequence[TotalRecursiveCallsNum][i];

		}

		TotalRecursiveCallsNum--;
	}

	GetMovingSequence_DivConquer(TotalRecursiveCallsNum);
}/*************************************End of Function***********************************************/



void TurnOffSwitches_DivConquer(){

	for(int i=1;i<TotalSwitch_Num;i++ ){

		for(int j=0;j<MovingSequencesNum;j++){

			if(CurrentSwitch_movingSequence[i][j]==0)
				break;
			int MovingSwitchIndex=CurrentSwitch_movingSequence[i][j];
			RowSwitches[MovingSwitchIndex-1]=!RowSwitches[MovingSwitchIndex-1];
			printArray_1D(RowSwitches,0, RowSwitchNum-1);
			TotalBasicOperation++;
		}
	}
}



int main(){

	GetMovingSequence_DivConquer( RowSwitchNum);
	printArray_2D();
	printf("\n");

	printf("The start state of the Array is ");
	printArray_1D(RowSwitches,0, RowSwitchNum-1);

	TurnOffSwitches_DivConquer();

	printf("Total basic operation is ");
    printf("%d",TotalBasicOperation);

}
