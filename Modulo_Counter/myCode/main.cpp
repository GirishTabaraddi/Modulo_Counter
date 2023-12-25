//! Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;

//! Project's header files here
#include "ModuloNCounter.h"
#include "ModuloNDigitCounter.h"

#define MAXCOUNTVALUE 20 //! Some arbitrary value as the max count value for the counter.

//!< Main program
int main()
{
	cout << "Modulo_Counter started." << endl << endl;

	int digits, type;

	do
	{
		//! get the input from user on what counter to be displayed on the console.
		cout << endl << endl << "Please enter the parameters of your counter: "
				<< endl;
		cout << "number of digits: ";
		cin >> digits;
		cout << endl << "type (2/8/10/16): ";
		cin >> type;

		//! Creating a Object to Single Digit Counter for Pre-Increment Operator Overloading.
		ModuloNCounter SingleCounterPreObj(type);
		//cout << " type value: " << type << endl;

		//! Print the name of the counter for Single Digit Modulo Pre-Increment Counter.
		cout << "Single Digit Modulo Pre-Increment Counter" << endl;

		//! For loop to run the counter till an arbitrary value defined as global variable in the main function.
		for (int i = 0; i < MAXCOUNTVALUE; i++)
		{
			ModuloNCounter SingleCounter1(++SingleCounterPreObj);//! Increment the Single Counter Object to perform Pre-Increment operator overloading.
			SingleCounter1.ModuloNCounterPrint(type); //! This created object calls the method ModuloNCounterPrint and prints the current value of the counter.
		}

		cout << endl << endl;
		//! Creating a Object to Single Digit Counter for Post-Increment Operator Overloading.
		ModuloNCounter SingleCounterPostObj(type);

		//! Print the name of the counter for Single Digit Modulo Post-Increment Counter.
		cout << "Single Digit Modulo Post-Increment Counter" << endl;

		//! For loop to run the counter till an arbitrary value defined as global variable in the main function.
		for (int i = 0; i < MAXCOUNTVALUE; i++)
		{
			ModuloNCounter SingleCounter2(SingleCounterPostObj++);//! Increment the Single Counter Object to perform Pre-Increment operator overloading.
			SingleCounter2.ModuloNCounterPrint(type); //! This created object calls the method ModuloNCounterPrint and prints the current value of the counter.
		}

		//! Check if the entered type is 2/8/10/16 only, if yes then call NDigitCounters method and NDigitCountersPrint to print the counters on the console.
		if ((digits > 0)
				&& (type == 2 || type == 8 || type == 10 || type == 16))
		{
			//! Creating an object for class ModuloNDigitCounter.
			ModuloNDigitCounter CountersPreObj(digits, type);
			ModuloNDigitCounter CountersPostObj(digits, type);
			cout << endl << endl;
			//! Call the print method to print the name of the module counter by passing the type got from user and enum to print the name of the counter.
			CountersPreObj.NDigitCountersPrint(type,
			ModuloNDigitCounter::COUNTERNAME);

			int column_formatter = 0; //! an integer variable for checking the column during counter print and is initialized to 0.

			//! if the type of counter is 8/10/16 then each line in the console should have 8/10/16 columns.
			if(type == 8 || type == 10 || type == 16)
			{
				cout << "Pre-Increment Operator overloading for Modulo Counter." << endl;
				for (int i = 0; i < MAXCOUNTVALUE; i++)
				{

					if (column_formatter < type)
					{
						ModuloNDigitCounter Counters(++CountersPreObj); //! Pre-Incrementing the object created for the ModuloNDigitCounter. Also, copying the constructor.
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters created object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter++;
					}
					else
					{
						cout << endl;
						ModuloNDigitCounter Counters(++CountersPreObj);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter = 1;
					}
				}

				column_formatter = 0;
				cout << endl << endl << "Post-Increment Operator overloading for Modulo Counter." << endl;
				for (int i = 0; i < MAXCOUNTVALUE; i++)
				{

					if (column_formatter < type)
					{
						ModuloNDigitCounter Counters(CountersPostObj++);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters(post-increment) created object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter++;
					}
					else
					{
						cout << endl;
						ModuloNDigitCounter Counters(CountersPostObj++);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters object(post-increment) calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter = 1;
					}
				}
			}

			//! if the type of counter is 2 then each line in the console should have 16 columns respectively.
			else if(type == 2)
			{
				cout << "Pre-Increment Operator overloading for Modulo-2 counter." << endl;
				for (int i = 0; i < MAXCOUNTVALUE; i++)
				{

					if (column_formatter < 16)
					{
						ModuloNDigitCounter Counters(++CountersPreObj); //! Pre-Incrementing the object created for the ModuloNDigitCounter. Also, copying the constructor.
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters created object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter++;
					}
					else
					{
						cout << endl;
						ModuloNDigitCounter Counters(++CountersPreObj);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter = 1;
					}
				}

				column_formatter = 0;
				cout << endl << endl << "Post-Increment Operator overloading for Modulo-2 counter." << endl;
				for (int i = 0; i < MAXCOUNTVALUE; i++)
				{

					if (column_formatter < 16)
					{
						ModuloNDigitCounter Counters(CountersPostObj++);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters(post-increment) created object calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter++;
					}
					else
					{
						cout << endl;
						ModuloNDigitCounter Counters(CountersPostObj++);
						Counters.NDigitCountersPrint(type,
								ModuloNDigitCounter::COUNTERVALUE); //! The Counters object(post-increment) calls the method ModuloNCounterPrint and prints the current value of the counter.
						column_formatter = 1;
					}
				}
			}
			//! Here the object created for the multi digit counter is calling the post-increment operator overloading.
			//! Also, the column will be formatted according to the type of the counter, for modulo-8 we will have 8 columns and similarly for modulo-10 counter.
			else
			{

			}
		}
		else
		{
			cout << "Not valid digit/type input" << endl;
		}
	} while (digits != 0 && type != 0); //! Check if the entered type is 0 and digits is also 0, if yes then end the test or else continue with the loop.

	cout << "End of test" << endl;

	return 0;
}/**END OF MAIN FUNCTION*/
