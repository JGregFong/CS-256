#include <stdio.h>

int allSeats = 450;
int rows = 15;
int columns = 30;
float BuySeats(char *array, float seatPrice[]);

int main(){
char theater[rows][columns];
for (int i = 0; i<rows; i++){
	for(int j = 0; j<columns; j++){
		theater[i][j] = '#';
	}
}
float prices[rows];

printf("Welcome to the Theatre Seating Form. \n");

printf("Please enter the seating prices for each row: \n");

for(int i = 0; i< rows; i++){
	printf("For Row %d, what is the price: $", i);
	fflush(stdout);
	float ticketPrice;
	scanf("%f", &ticketPrice);
	prices[i] = ticketPrice;
	printf("Row %d Price Recorded.\n",i);
}

printf("\t\t Seating\n");

printf("\t\t Seating \n");
printf("\t 012345678901234567890123456789\n");
for(int i=0; i<rows; i++){
	printf("Row %d:\t ",i);
	for(int j = 0; j<columns; j++){
		printf("%c", theater [i][j]);
	}
	printf("\n");
}


printf("Please select from any of the choices below: \n");
printf("1. Buy Seats \n");
printf("2. Check Ticket Sales\n");
printf("3. Check Seat Availability\n");
printf("4. Check Seat Statistics\n");
printf("5. Exit\n");
printf("What is your choice? ");
int choice;


do{
fflush(stdout);
scanf("%d", &choice);
switch(choice){
case 1:
	ticketSales += BuySeats(*theater, prices);
	break;
case 2:

	break;
case 3:

	break;
case 4:

	break;
case 5:

	break;
default:
	printf("That is not a valid choice.");
	printf("Please select from any of the choices below: \n");
	printf("1. Buy Seats \n");
	printf("2. Check Ticket Sales\n");
	printf("3. Check Seat Availability\n");
	printf("4. Check Seat Statistics\n");
	printf("5. Exit\n");
	printf("What is your choice? ");

	break;

}
}
while(choice!= 5);

	return 0;
}

float BuySeats(char *array, float seatPrice[] ){

	float bought = 0;

	printf("How many seats do you wish to get? ");
	fflush(stdout);
	int amount;
	fflush(stdout);
	scanf("%d", &amount);

	int done = 0;

	printf("\n Please enter the row and column for each seat you wish to buy. \n");

	while(done<amount){
		int row, column;
		printf("Please enter the location of seat %d: [row] [column]", done+1);
		fflush(stdout);
		scanf("%d %d", &row, &column);
		int assigned = 0;
		char check  = *(array+(row*column));
		do{
			if(check == '*' && assigned == 0){
				printf("The seat at Row %d Column %d is taken, please choose another seat. \n", row, column);
				printf("[Row] [Column]: ");
				fflush(stdout);
				scanf("%d %d", &row, &column);
				check = *(array+(row*column));
			}
			else{

				*(array+(row*column)) = '*';
				bought += seatPrice[row];
				assigned = 1;
				printf("Seat at %d %d has been successfully acquired at a price of $ %.2f \n", row, column, seatPrice[row]);

			}

		}
	while(check == '*' && assigned == 0);
		printf("\t\t Seating \n");
		printf("\t 012345678901234567890123456789\n");
		for(int i=0; i<rows; i++){
			printf("Row %d:\t ",i);
			for(int j = 0; j<columns; j++){
				printf("%c", *(array+(i*j)));
			}
			printf("\n");
		}
		done++;
	}





	printf("You bought all your seats. \n");

	return bought;
}

int CheckSeats(char chart[rows][columns]){
	int taken = 0;
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<columns; j++){
			if(chart[i][j] == '*'){
				taken++;
			}
		}
	}

	return 0;
}
