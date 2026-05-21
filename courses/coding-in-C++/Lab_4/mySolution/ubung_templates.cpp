#include <iostream>
#include <string>

// Einfaches Pair-Template für zwei unterschiedliche Typen
template<typename T1, typename T2>
class Pair {
private:
	T1 first_;
	T2 second_;
public:
	// Konstruktor, der beide Werte setzt
	Pair() = default;
	Pair(const T1& a, const T2& b) : first_(a), second_(b) {}

	// Getter-Methoden
	const T1& getFirst() const { return first_; }
	const T2& getSecond() const { return second_; }

	// Setter-Methoden
	void setFirst(const T1& a) { first_ = a; }
	void setSecond(const T2& b) { second_ = b; }
};

// Kleines Beispiel zur Nutzung
int main() {
	Pair<int, std::string> p(0, "");
	std::cout << "Gib eine ganze Zahl und ein Wort ein: ";
	int n; std::string s;
	if (std::cin >> n >> s) {
		p.setFirst(n);
		p.setSecond(s);
		std::cout << "Erstes: " << p.getFirst() << ", Zweites: " << p.getSecond() << std::endl;
	}
	return 0;
}

