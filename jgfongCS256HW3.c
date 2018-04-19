#include <stdio.h>

float PI = 3.14159;

void GeometryCalculator();
void Population();
void TicTacToe();
int  *ReverseArray(int array[], int size);

int WinCheck(char[][]);

int main(){

	int choice;

	printf("Welcome to Jonathan Fong's CS256 HW3\n");
	printf("1. Geometry Calculator\n");
	printf("2. Population\n");
	printf("3. Tic-Tac-Toe\n");
	printf("4. Reverse Array\n");
	printf("5. Exit\n");
	printf("Please type in a number [1-5]:");
	fflush(stdout);
	scanf("%d", &choice);

	do{
		switch(choice){
		case 1:
			printf("Geometry Calculator Starting");
			GeometryCalculator();
			break;
		case 2:
			printf("Population Function Start");
			Population();
			break;
		case 3:
			printf("Tic-Tac-Toe Starting");
			TicTacToe();
			break;
		case 4:
			printf("Reverse Array Starting");
			int array[5] = {5, 10, 15, 20, 25};
			int size = sizeof(array)/sizeof(array[0]);
			printf("Array being inputted. {%d, %d, %d, %d, %d} \n", array[0], array[1], array[2], array[3], array[4]);


			int *reversedArray = ReverseArray(array, size);
			printf("Reversed array: \n");
			for(int i = 0; i< size; i++){
				printf(" %d", *reversedArray);
				reversedArray++;
			}
			break;
		case 5:
			printf("Exiting.");
			break;
		default:
			printf("That is not a valid input.\n");
			printf("Welcome to Jonathan Fong's CS256 HW3\n");
			printf("1. Geometry Calculator\n");
			printf("2. Population\n");
			printf("3. Tic-Tac-Toe\n");
			printf("4. Reverse Array\n");
			printf("5. Exit\n");
			fflush(stdout);
			scanf("%d", &choice);
			break;
		}
	}
	while(choice!=5);


	return 0;
}

void GeometryCalculator(){

	float radius;
	float width;
	float height;
	float area;

	int choice1;
	printf("Welcome to Geometry Calculator. \n");
	printf("1. Calculate the Area of a Circle. \n");
	printf("2. Calculate the Area of a Rectangle.\n");
	printf("3. Calculate the Area of a Triangle.\n");
	printf("4. Quit \n");
	printf("Please enter your selection [1-4]: \n");
	fflush(stdout);
	scanf("%d", choice1);
	while(choice1 != 4){

		switch(choice1){
		case 1:
			printf("Enter the radius of your circle:");
			fflush(stdout);
			scanf("%f", &radius);
			area = PI *radius *radius;
			printf("Your circle's area is %f", area);
			break;
		case 2:
			printf("Enter the height of your rectangle:");
			fflush(stdout);
			scanf("%f", &height);
			printf("Enter the width of your rectangle:");
			fflush(stdout);
			scanf("%f", &width);
			area = height * width;
			printf("Your rectangle's area is %f \n", area);
			break;
		case 3:
			printf("Enter the width of your triangle: ");
			fflush(stdout);
			scanf("%f", &width);
			printf("Enter the height of your triangle: ");
			fflush(stdout);
			scanf("%f", &height);
			area = .5*width*height;
			printf("Your triangle's area is %f \n", area);
			break;
		case 4:
			break;
		default:
			printf("Welcome to Geometry Calculator\n");
			printf("1. Calculate the Area of a Circle. \n");
			printf("2. Calculate the Area of a Rectangle.\n");
			printf("3. Calculate the Area of a Triangle.\n");
			printf("4. Quit \n");
			printf("Please enter your selection: \n");
			fflush(stdout);
			scanf("%d", &choice1);
			break;
		}
	}


}
void Population(){

	int startPop;
	int newPop;
	int birthRate;
	int deathRate;
	int years;

	printf("Population Function\n");
	printf("Please enter the starting size of the population: ");
	fflush(stdout);
	scanf("%d", &startPop);
	if(startPop<2){
		while(startPop<2){
			printf("The starting population cannot be under 2.");
			fflush(stdout);
			scanf("%d", &startPop);
		}
	}
	printf("Please enter the annual birth rate: ");
	scanf("%d", &birthRate);
	if(birthRate <0){
		while(birthRate<0){
			printf("The annual birth rate cannot be a negative integer.");
			fflush(stdout);
			scanf("%d", &birthRate);
		}
	}
	printf("Please enter the annual death rate: ");
	scanf("%d", &deathRate);
	if(deathRate <0){
		while(deathRate<0){
			printf("The annual death rate cannot be a negative integer.");
			fflush(stdout);
			scanf("%d", &deathRate);
		}
	}
	printf("Please enter the number of years: ");
	scanf("%d", &years);
	if(years <1){
		while(years<1){
			printf("The number of years cannot be less than 1.");
			fflush(stdout);
			scanf("%d", &years);
		}
	}

	for(int loop = 0; loop< years; loop++){
		newPop = startPop + birthRate - deathRate;
		startPop = newPop;
	}

	printf("New Population: %d", newPop);

}
void TicTacToe(){

	char grid [3][3] ={{ '*' , '*' , '*' }, { '*' , '*' , '*' }, { '*' , '*' , '*' }};


	int done = 0;

	int turn = 1;
	int player = 1;
	int gameStatus = -1;

	int row;
	int column;
	while(done ==0){

		printf("Turn %d\n", turn);
		printf("=======================\n");
		printf("[  ] [0 ] [1 ] [2 ]\n");
		printf("[0 ] [%c] [%c] [%c]\n", grid[0][0], grid[0][1], grid[0][2]);
		printf("[1 ] [%c] [%c] [%c]\n", grid[1][0], grid[1][1], grid[1][2]);
		printf("[2 ] [%c] [%c] [%c]\n", grid[2][0], grid[2][1], grid[2][2]);
		printf("=======================\n");

		printf("Player %d: Please enter your selection: [row] [column]\n", player);
		fflush(stdout);
		scanf("%d %d", &row, &column);

		if(player == 1){
			grid[row][column] = 'X';
		}
		gameStatus = WinCheck(grid);

		if(gameStatus == -1){
			done = 0;
			player = 2;
		}
		else if(gameStatus == 0){

			done = 1;
		}
		else{
			done = 1;
		}

		if(done == 0){
		printf("=======================\n");
		printf("[  ] [0 ] [1 ] [2 ]\n");
		printf("[0 ] [%c] [%c] [%c]\n", grid[0][0], grid[0][1], grid[0][2]);
		printf("[1 ] [%c] [%c] [%c]\n", grid[1][0], grid[1][1], grid[1][2]);
		printf("[2 ] [%c] [%c] [%c]\n", grid[2][0], grid[2][1], grid[2][2]);
		printf("=======================\n");

		printf("Player %d: Please enter your selection: [row] [column]\n", player);
		fflush(stdout);
		scanf("%d %d", &row, &column);


		if(player == 2){
			grid[row][column] = 'O';
		}

		gameStatus = WinCheck(grid);

		if(gameStatus == -1){
			done = 0;
			player = 1;
		}
		else if(gameStatus == 0){

			done = 1;
		}
		else{
			done = 1;
		}
		turn++;
		}

	}

		printf("=======================\n");
		printf("[  ] [0] [1] [2]\n");
		printf("[0 ] [%c] [%c] [%c]\n", grid[0][0], grid[0][1], grid[0][2]);
		printf("[1 ] [%c] [%c] [%c]\n", grid[1][0], grid[1][1], grid[1][2]);
		printf("[2 ] [%c] [%c] [%c]\n", grid[2][0], grid[2][1], grid[2][2]);
		printf("=======================\n");
		printf("Congrats, Player %d ! You win.", player);

}

int WinCheck(char grid[3][3]){

	if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] != '*'){
		return 1; // Top row
	}
	else if(grid[0][0] == grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0] != '*'){
		return 1; // Left top to right bottom diagonal
	}
	else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] != '*'){
		return 1; // Left column
	}
	else if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][0] != '*'){
		return 1; // Middle row
	}
	else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] != '*'){
		return 1; // Middle column
	}
	else if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] != '*'){
		return 1; // Bottom row
	}
	else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] != '*'){
		return 1; // Right column
	}
	else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '*'){
		return 1; //Right top to left bottom diagonal
	}
	else if(grid[0][0] !='*' && grid[0][1] != '*' && grid[0][2] !='*' && grid[1][0] != '*' && grid[1][1] !='*'
			&& grid[1][2] !='*' && grid[2][0] !='*' && grid[2][1] !='*' && grid[2][2] !='*'){
		return 0; //Game draw
	}
	else{
		return -1; //Game ongoing
	}
}

int * ReverseArray(int array[], int size){

	static int newArray[5];
	int counter = size-1;
	for(int i = 0; i< size; i++){
		newArray[i]= array[counter - i];
	}
	return newArray;

}

