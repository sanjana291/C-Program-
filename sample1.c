#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

 int** BinRead(char* filename, int row, int col, int raw);
void freeArrayint(int rows,   int** data);

int main()
{
	char* delayfile="DelayCheck.bin";
	int row = 2611;
	int col = 64;
	int raw = row * col;
	
	int **delayData=BinRead(delayfile, row, col, raw);
	freeArrayint(row, delayData);
	return 0;

}

 int** BinRead(char* filename, int row, int col, int raw)
{
	FILE *file;
	int i,j,k;
	int *temp = NULL;
	temp=(int*)malloc(raw*sizeof(int));
	
	 int **Data = NULL;
	Data=( int**)malloc(row* sizeof( int));
	for( i=0; i<row; i++)
		Data[i]=( int*)malloc(col* sizeof( int));
	if (Data== NULL)
		printf("Memory is not Allocated for Data.\n");
	else
		printf("Memory is allocated Successfully for Data.\n");	
	
	file=fopen(filename,"rb");
	
	if(file != NULL)
	{
		fread(temp, sizeof(int), raw, file);
		fclose(file);
		k=0;
		while(k<raw)
		{
			for(i=0;i<col;i++)
			{
				for(j=0;j<row;j++)
				{
					Data[i][j]=temp[k];
					k++;
					//printf("%d ",Data[i][j]);
					printf("delay[%d][%d]=%d:raw[%d]\n",i,j,Data[i][j],k);
					if(k==raw)
						printf("delay is done!");
				}
				//printf("\n");
			}
		}
		free(temp);
	
	}
	else
		printf("Error in File Opening");
	
	return Data;
}
void freeArrayint(int rows,  int** data) {
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);
}