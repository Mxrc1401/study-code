#include <iostream>
#include <string>

class DrinkBuilder {
private:
	static constexpr int DEFAULT_TEMPERATURE = 60;
	static constexpr int MAX_SUGAR = 10;

	std::string name;
	int sugar;
	int temperature;
	bool withMilk;

public:
    DrinkBuilder()
		: name("Water"), sugar(0), temperature(DEFAULT_TEMPERATURE), withMilk(false) {
	}

    DrinkBuilder& setName(const std::string& newName) {
		name = newName;
		return *this;
	}
	
    DrinkBuilder& setSugar(int newSugar) {
		if (newSugar >= 0 && newSugar <= MAX_SUGAR) {
			sugar = newSugar;
		}
		return *this;
	}

    DrinkBuilder& setTemperature(int newTemperature) {
		if (newTemperature > 0) {
			temperature = newTemperature;
		}
		return *this;
	}

    DrinkBuilder& setWithMilk(bool hasMilk) {
		withMilk = hasMilk;
		return *this;
	}

    bool isValid() const {
		return !name.empty() && sugar >= 0 && sugar <= MAX_SUGAR && temperature > 0;
	}

	void print() const {
		std::cout << "Drink: " << name << '\n';
		std::cout << "Sugar: " << sugar << '\n';
		std::cout << "Temperature: " << temperature << '\n';
		std::cout << "With milk: " << (withMilk ? "true" : "false") << '\n';
	}
};



/////////////////////////////////////////////MAIN/////////////////////////////////////////////////
int main() {

    DrinkBuilder builder;
	builder.setName("Cofee")
		.setSugar(1)
		.setTemperature(60)
		.setWithMilk(true)
		.print();

    std::cout << "Valid: " << (builder.isValid() ? "true" : "false") << '\n';

	return 0;
}
/////////////////////////////////////////////MAIN/////////////////////////////////////////////////
