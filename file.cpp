#include <iostream>
#include <string>
#include <cmath>

/*
	Write a program that allows you to enter the value of the entire type of base variable. base can be:
	Any number in the range 2-16

	The user will enter 8-dimensional lines, any of which will be {'0', '1', '2', '3', '4', '5', '6', '7', '8', ' 9 ',' A ',' B ',' C ',' D ',' E ',' F '} range.
	The entered line is a representation of a certain number of 10 in a base-based digital system.
*/

int main()
{
	int base = 0;

	int* ptr = new int;
	*ptr = 0;
	std::cout << "Enter numbers base(2-16): ";
	do {
		std::cin >> base;

		if (base < 2 || base > 16) {
			if (*ptr < 3) {
				std::cout << "Base can only was 2-16. You entered '" << base << "' number\n"
									<< "Try again: ";
			}
			else if (*ptr >= 3 && *ptr <= 6) {
				std::cout << "When i said that write 2-16 numbers, i can say write ";
				for (int i = 2; i < 16; ++i) {
					std::cout << i << " or ";
				}
				std::cout << "16 number..\nTry it: ";
			}
			else {
				std::cout << "I dont know how i can say you.. bye...";
				return -1;
			}

			(*ptr)++;
		}
	} while (base < 2 || base > 16);

	delete ptr;

	std::string number = {};
	std::cout << "Enter number(0-";
	switch (base) {
		case 11: { std::cout << "A"; break; }
		case 12: { std::cout << "B"; break; }
		case 13: { std::cout << "C"; break; }
		case 14: { std::cout << "D"; break; }
		case 15: { std::cout << "E"; break; }
		case 16: { std::cout << "F"; break; }
		default: { std::cout << base - 1; break; }
	}
	std::cout << "): ";
	std::cin >> number;

	std::cout << "\nNumber: " << number << ", Base: " << base << std::endl;

	int index = number.size() - 1;

	int sum = 0;
	for (int i = 0; i < number.size(); ++i, --index) {
		int tempNumber = -1;

		switch (number[i]) {
			// deciman numbers
			case 48: { tempNumber = 0; break; }
			case 49: { tempNumber = 1; break; }
			case 50: { tempNumber = 2; break; }
			case 51: { tempNumber = 3; break; }
			case 52: { tempNumber = 4; break; }
			case 53: { tempNumber = 5; break; }
			case 54: { tempNumber = 6; break; }
			case 55: { tempNumber = 7; break; }
			case 56: { tempNumber = 8; break; }
			case 57: { tempNumber = 9; break; }

			// heximal numbers UPPERCASE
			case 65: { tempNumber = 10; break; }
			case 66: { tempNumber = 11; break; }
			case 67: { tempNumber = 12; break; }
			case 68: { tempNumber = 13; break; }
			case 69: { tempNumber = 14; break; }
			case 70: { tempNumber = 15; break; }
			
			// heximal numbers LOWERCASE
			case 97: { tempNumber = 10; break; }
			case 98: { tempNumber = 11; break; }
			case 99: { tempNumber = 12; break; }
			case 100: { tempNumber = 13; break; }
			case 101: { tempNumber = 14; break; }
			case 102: { tempNumber = 15; break; }

			default: { std::cout << "invalid symbol -> " << number[i] << " <- index: " << i << "\n"; return -1; }
		}

		if (tempNumber >= base) {
			std::cout << "Your number isn't base system: -> " << tempNumber << " <- index: " << i << "\n";
			return -1;
		}
		// DEBUGGING
		/*std::cout << "\n======================================"
							<< "\ntempNumber: " << tempNumber
							<< "\nbase, index: " << base << ", " << index
							<< "\npow: " << pow(base, index)
							<< "\nSum (in for): " << sum;*/
		//end DEBUGGING
		sum += tempNumber * pow(base, index);
	}
	std::cout << "Sum: " << sum;
	return 0;

}