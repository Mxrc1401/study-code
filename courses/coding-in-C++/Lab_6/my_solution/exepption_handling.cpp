
#include <iostream>
#include <string>




class ConfigLoader
{
public:
	void load(const std::string& filename)
	{
		if (filename.empty())
		{
			throw std::invalid_argument("Dateiname darf nicht leer sein.");
		}

		if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".cfg")
		{
			throw std::invalid_argument("Nur Dateien mit der Endung .cfg sind erlaubt.");
		}
    
	
};
};

int main()
{
}
