#include <stdio.h>

void main(void)

{

float height, width, area, wood_length, price_of_wood, price_of_glass, total_price;


printf("Enter height ");
scanf("%f", &height);
printf("Enter width ");
scanf("%f", &width);

area = 2 * height * width;
wood_length = 2 * (height + width) * 3.25;
price_of_wood = 50 * wood_length;
price_of_glass = 300 * area;
total_price = (price_of_glass + price_of_wood);

printf("The area of glass needed is : %.2f metres.\n", area);
printf("The length of wood needed is : %.4f feet.\n", wood_length);
printf("The price of glass needed is : %.2f ksh.\n", price_of_glass);
printf("The price of wood needed is : %.2f ksh.\n", price_of_wood);
printf("The total price of materials is %.2f ksh.\n", total_price);

}
