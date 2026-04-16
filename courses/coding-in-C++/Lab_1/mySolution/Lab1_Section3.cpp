#include <cstdint>
#include <iostream>
#include <limits>


namespace validation
{
bool isAdult(std::uint8_t age)
{
	return age >= 18;
}

bool isSenior(std::uint8_t age)
{
	return age >= 65;
}
}
/////////////////////////////////////MAIN//////////////////////////////////////
int main()
{
	const int MIN_ALTER = 0;
	const int MAX_ALTER = 120;

	std::uint8_t alter = 0;
	int eingabe = 0;
	bool ist_gueltig = false;

	while (!ist_gueltig)
	{
		std::cout << "Enter your age: ";

		if (!(std::cin >> eingabe))
		{
			std::cout << "You did not enter a valid number." << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((eingabe < MIN_ALTER) || (eingabe > MAX_ALTER))
		{
			std::cout << "You did not enter a valid number." << std::endl;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		alter = static_cast<std::uint8_t>(eingabe);
		ist_gueltig = true;
	}

	std::cout << "Your age is :" << static_cast<int>(alter) << std::endl;

	if (validation::isSenior(static_cast<std::uint8_t>(alter)))
	{
		std::cout << "==> That means that you are a senior citizen." << std::endl;
	}
	else if (validation::isAdult(static_cast<std::uint8_t>(alter)))
	{
		std::cout << "==> That means that you are an adult." << std::endl;
	}
	else
	{
		std::cout << "==> That means that you are still a kid or a teenager." << std::endl;
	}

	return 0;
}
/////////////////////////////////////MAIN//////////////////////////////////////
