#include <stdio.h>

/**
 * main - Entry point
 * Description: This programme prints the total cost of  materials
 * It also prints the total material cost per window
 *Return:Always 0 (success)
 */

void main(void)

{

float cost, number_of_windows, height, width, area, wood_length, price_of_wood, price_of_glass, total_price;

printf("Enter height ");
scanf("%f", &height);
printf("Enter width ");
scanf("%f", &width);
printf("Enter number of windows ");
scanf("%f", &number_of_windows);

area = height * width;
wood_length = 2 * (height + width) + 0.6;
price_of_wood = 50 * wood_length;
price_of_glass = 1300 * area;
total_price = (price_of_glass + price_of_wood);
cost = total_price *number_of_windows;

printf("The area of glass needed is : %.2f metres.\n", area);
printf("The length of wood needed is : %.4f feet.\n", wood_length);
printf("The price of glass needed is : %.2f ksh.\n", price_of_glass);
printf("The price of wood needed is : %.2f ksh.\n", price_of_wood);
printf("The total price of materials is %.2f ksh.\n", total_price);
printf("The total cost of windows is %.2f ksh.\n", cost);

}
