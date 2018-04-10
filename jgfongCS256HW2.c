#include <stdio.h>

void foodBill();
void oceanLevels();


int main(){


	return 0;
}

void foodBill(){

	float mealCost = 88.67f, taxAmount, tipAmount,total;

	taxAmount = mealCost * .0675;
	total = mealCost + taxAmount;
	tipAmount = (total) * .2;
	total += tipAmount;

	printf("Restaurant Bill \n");
	printf("Meal Cost: $" + mealCost + "\n");
	printf("Tax Amount: $" + taxAmount + "\n");
	printf("Tip Amount: $" + tipAmount + "\n");
	printf("Total Bill: $" + total + "\n");

}

void oceanLevels(){

	float oceanRise = 1.5f;

	float oceanFive, oceanSeven, oceanTen;
	oceanFive = 5 *

	printf("The ocean's level will be ");

}
