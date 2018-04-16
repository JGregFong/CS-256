#include <stdio.h>

float PI = 3.14159;



int main(){

	int choice;

	printf("Welcome to Jonathan Fong's CS256 HW3\n");
	printf("1. Geometry Calculator\n");
	printf("2. Population\n");
	printf("3. Tic-Tac-Toe\n");
	printf("4. Reverse Array\n");
	printf("5. Exit");

	scanf("%d", &choice);

	while(choice!= 5){
		switch(choice){
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:

			return 0;

			break;
		default:
			printf("That is not a valid input.\n");
			printf("Welcome to Jonathan Fong's CS256 HW3\n");
			printf("1. Geometry Calculator\n");
			printf("2. Population\n");
			printf("3. Tic-Tac-Toe\n");
			printf("4. Reverse Array\n");
			printf("5. Exit\n");
			scanf("%d", &choice);
			break;
		}
	}
	return 0;
}

void GeometryCalculator(){

	float radius;
	float width;
	float height;
	float area;

	char choice1;


	while(choice1 != 4){
	printf("Welcome to Geometry Calculator\n");
	printf("1. Calculate the Area of a Circle. \n");
	printf("2. Calculate the Area of a Rectangle.\n");
	printf("3. Calculate the Area of a Triangle.\n");
	printf("4. Quit \n");
	printf("Please enter your selection: \n");
		switch(choice1){
		case'1':
			printf("Enter the radius of your circle:");
			scanf("%f", radius);
			area = PI *radius *radius;
			printf("Your circle's area")
			break;
		case'2':
			break;
		case'3':
			break;
		case'4':
			break;
		default:
			printf("Welcome to Geometry Calculator\n");
			printf("1. Calculate the Area of a Circle. \n");
			printf("2. Calculate the Area of a Rectangle.\n");
			printf("3. Calculate the Area of a Triangle.\n");
			printf("4. Quit \n");
			printf("Please enter your selection: \n");
			break;
		}
	}


}
