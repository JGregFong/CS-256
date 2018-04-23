#include <stdio.h>

int allSeats = 450;
int rows = 15;
int columns = 30;
float BuySeats(char *array, float seatPrice[]);
int CheckSeats(char chart [][30]);

int main(){
char theater[rows][columns];
for (int i = 0; i<rows; i++){
	for(int j = 0; j<columns; j++){
		theater[i][j] = '#';
	}
}
float prices[rows];
float ticketSales = 0;

int available = 0;
int seatsTaken;
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

printf("\t\t Seating \n");
printf("\t 012345678901234567890123456789\n");
for(int i=0; i<rows; i++){
	printf("Row %d:\t ",i);
	for(int j = 0; j<columns; j++){
		printf("%c", theater [i][j]);
	}
	printf("\n");
}


int choice;

do{
printf("Please select from any of the choices below: \n");
printf("1. Buy Seats \n");
printf("2. Check Ticket Sales\n");
printf("3. Check Seat Availability and Data\n");
printf("4. Exit\n");
printf("What is your choice? ");
fflush(stdout);
scanf("%d", &choice);
switch(choice){
case 1:
	ticketSales += BuySeats(*theater, prices);
	break;
case 2:
	printf("The amount of money gained: $%.2f \n", ticketSales);

	break;
case 3:

	seatsTaken = CheckSeats(theater);
	available = allSeats - seatsTaken;
	printf("Seats available in theatre: %d\n", available);
	break;
case 4:
	printf("Exiting program. \n");
	break;
default:
	printf("That is not a valid choice.\n");


	break;

}
}
while(choice!= 4);

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
				check = *(array+(row*columns + column));
			}
			else{

				*(array+(row*columns + column)) = '*';
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
				printf("%c", *(array+(i*columns +j)));
			}
			printf("\n");
		}
		done++;
	}

	printf("You bought all your seats. \n");
	printf("$%.2f worth of seats bought. \n", bought);

	return bought;
}

int CheckSeats(char chart[rows][columns]){
	int taken = 0;

	for(int i = 0; i<rows; i++){
		int rowSeatsTaken = 0;
		for(int j = 0; j<columns; j++){
			if(chart[i][j] == '*'){
				taken++;
				rowSeatsTaken++;
			}
		}
		printf("For Row %d, %d seats have been filled.\n", i, rowSeatsTaken);
		printf("For Row %d, %d seats are empty. \n", i, columns-rowSeatsTaken);
	}

	return taken;
}
