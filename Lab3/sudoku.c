#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>




int rank=9;
int board[rank][rank];
int colsum=0;
int rowsum=0;
bool Rvalid=true;
bool Cvalid=true;
int num;


pthread_mutex_t mutex;

void *read_file(void *arg){
	pthread_mutex_lock(&mutex);
	FILE *fp = fopen("Input.txt","r");
	fseek (fp, 0L, SEEK_END); //move to the end of file
	int size = ftell(fp); //get the size
	fseek (fp, 0, SEEK_SET); //set back to beginning of the file
	if (size == 0) {
		printf ("Empty file");
	} 	else {
		for (int i=0; i<rank; i++) {
			for (int j=0; j<rank; j++) {
				fscanf(fp, "%d", &puzzle[i][j]);}
		}
	}
		fclose(fp);
		pthread_mutex_unlock(&mutex);
}


void *print_board(void *arg){
	pthread_mutex_lock(&mutex);
	for (int i=0; i<rank; i++) {
		for (int j=0; j<rank; j++) {
			if (board[i][j]!=NULL){
			printf("%d", board[i][j]");}
			else {
				printf("-"); }
			}
			printf("\n");
		}
		pthread_mutex_unlock(&mutex);
	}

void *checkRowValid(void *arg){
		pthread_mutex_lock(&mutex);

		Rvalid=true;
		for (int i=0; i<rank; i++) {
			for (int j=0; j<rank; j++) {
				if (board[i][j]!=NULL){
				sumRow=board[i][j]+sumRow;
		  	}
				else {
					sumRow=1+sumRow;
				}
				if (sumRow>9){
					Rvalid=false;
					break;
				}

				}
			}
			pthread_mutex_unlock(&mutex);

	}

	void *checkColValid(void *arg){
		pthread_mutex_lock(&mutex);
		Cvalid=true;

		for (int i=0; i<rank; i++) {
			for (int j=0; j<rank; j++) {
				if (board[j][i]!=NULL){
				sumCol=board[j][i]+sumCol;
				}
				else {
					sumCol=1+sumCol;
				}
				if (sumCol>9){
					Cvalid=false;
					break;
				}

				}
			}
			pthread_mutex_unlock(&mutex);

	}



	bool isInRow(int num, int row){
		for (int j=0; j<rank; j++) {
			if (board[row][j]==num){
				return true;
			}

	}
	return false
}

bool isInCol(int num, int col){
	for (int i=0; i<rank; i++) {
		if (board[i][col]==num){
			return true;
		}
}
return false
}

bool isInBox(int num, int rowPoint, int colPoint){
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (board[i+rowPoint][j+colPoint] == num) {
				return true;
			}
}
}
return false;

bool duplicates(int num,int row, int col){
	if (isInRow(num,row)==false&& isInCol(num,col)==false&& isInBox(num,row-row%3,col-col%3)){
		return true;
	} else {
		return false;
	}
	
}


main(){




}
