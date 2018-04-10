#include <stdio.h>

void foodBill();
void oceanLevels();


int main(){

	foodBill();

	return 0;
}

void foodBill(){

	float mealCost = 88.67f, taxAmount, tipAmount,total;

	taxAmount = mealCost * .0675;
	total = mealCost + taxAmount;
	tipAmount = (total) * .2;
	total += tipAmount;

	printf("Restaurant Bill \n");
	printf("Meal Cost: $%.2f\n", mealCost);
	printf("Tax Amount: $%.2f\n", taxAmount);
	printf("Tip Amount: $%.2f\n", tipAmount);
	printf("Total Bill: $%.2f\n", total);

}

void oceanLevels(){

	float oceanRise = 1.5f;

	float oceanFive, oceanSeven, oceanTen;
	oceanFive = 5 *

	printf("The ocean's level will be ");

}
