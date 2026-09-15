#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const float PRICE_OF_BMW = 40000, PRICE_OF_TOYOTA = 23000, PRICE_OF_FORD = 35000;

	int numofBMW, numofToyota, numofFORD, totalofBMWSold, totalofToyotaSold, totalofFordSold, totalPriceofall;

	cout << "Enter number of BMWs sold: ";
	cin >> numofBMW;

	cout << "Enter number of Toyotas sold: ";
	cin >> numofToyota;

	cout << "Enter number of Fords sold: ";
	cin >> numofFORD;


	totalofBMWSold = numofBMW * PRICE_OF_BMW;

	totalofToyotaSold = numofToyota * PRICE_OF_TOYOTA;

	totalofFordSold = numofFORD * PRICE_OF_FORD;

	totalPriceofall = totalofBMWSold + totalofToyotaSold + totalofFordSold;

	cout << "The total sales of BMW cars sold: " << totalofBMWSold << endl;

	cout << "The total sales of Toyota cars sold: " << totalofToyotaSold << endl;

	cout << "The total sales of Ford cars sold: " << totalofFordSold << endl;

	cout << "The total sales of all cars sold: " << totalPriceofall << endl;



	system("pause");
	return 0;

}