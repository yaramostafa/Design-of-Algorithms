#include <stdio.h>

int TotalBasicOperation=0;
int IndexLastMove=-99;

void printArray(int RowArray[],int startIndex, int EndIndex){

    for(int m=startIndex; m<=EndIndex;m++){
      printf("%d",RowArray[m]);
    }
    printf("\n");
}

char ChekAllSwitchesOff(int RowArray[],int start, int end){

	for(int j=start; j<=end; j++){
		if(RowArray[j] == 1){
			return 'F';
		}
	}
	return 'T';
}

int SearchSwitchIndex_Lock(int RowSwitches[],int StartIndex_LeftSideArray, int EndIndex_RightsideArray ){

for (int currentPosition = StartIndex_LeftSideArray ; currentPosition <=EndIndex_RightsideArray; currentPosition++){

int Flag_IsMovable=1;


if(currentPosition == EndIndex_RightsideArray){
TotalBasicOperation++;
return EndIndex_RightsideArray;
}

else if((currentPosition == EndIndex_RightsideArray-1) && (currentPosition !=IndexLastMove)){

if(RowSwitches[currentPosition + 1]==1){
TotalBasicOperation++;
if(TotalBasicOperation == 1)
	return currentPosition + ((EndIndex_RightsideArray+1)%2);
else
	return currentPosition;

 }
}/**********End of else if******************/

else if(RowSwitches[currentPosition+1] == 1){
for(int i=currentPosition+2; i<=EndIndex_RightsideArray; i++){
	if(RowSwitches[i] == 1){
		Flag_IsMovable = 0;
	 }
 }
if(1 == Flag_IsMovable && currentPosition != IndexLastMove){
	TotalBasicOperation++;
	return currentPosition;
  }

  }/************* End of else if condition **********************/
 }/*****************End of bigger for loop ***************************/
}/**************************End of function *************************************/



void TurnOffAllSwitches_BruteForce(int RowSwitches[],int StartIndex_LeftSideArray, int EndIndex_RightsideArray){



while('F' == ChekAllSwitchesOff(RowSwitches,StartIndex_LeftSideArray, EndIndex_RightsideArray)){
int CurrentMoveSwitchIndex= SearchSwitchIndex_Lock(RowSwitches, StartIndex_LeftSideArray, EndIndex_RightsideArray );
RowSwitches[CurrentMoveSwitchIndex]= !RowSwitches[CurrentMoveSwitchIndex];
printArray(RowSwitches,StartIndex_LeftSideArray, EndIndex_RightsideArray);

IndexLastMove=CurrentMoveSwitchIndex;
}
}


int main(){



int Arr[10]={1,1,1,1,1,1,1,1,1,1};
printf("The start state of the Array is ");
printArray(Arr,0, 9);




TurnOffAllSwitches_BruteForce(Arr,0,9);



printf("Total Number of Moves is ");
printf("%d",TotalBasicOperation);



}
