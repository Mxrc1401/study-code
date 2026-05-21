#include <iostream>
#include <iomanip>

int main() {
	double a, b, c, d;

	std::cout << "Gib 4 Zahlen ein (mit Leerzeichen getrennt): ";
	std::cin >> a >> b >> c >> d;

	if (!std::cin) {
		std::cout << "Ungueltige Eingabe. Bitte nur Zahlen eingeben.\n";
		return 1;
	}

	double durchschnitt = (a + b + c + d) / 4.0;

	std::cout << "\nDurchschnitt: " << std::fixed << std::setprecision(2)
			  << durchschnitt << "\n\n";

	std::cout << "Cooles Bild (+):\n";
	std::cout << "      +      \n";
	std::cout << "      +      \n";
	std::cout << "  +++++++++  \n";
	std::cout << "      +      \n";
	std::cout << "      +      \n";
	std::cout << "   \\\ | /   \n";
	std::cout << " --  (o o)  --\n";
	std::cout << "   /  |_|  \\\n";

	return 0;
}
