#include <iostream>
#include <string>

class Note 
{
private:
    std::string* text;

public:
    Note(std::string input_text)
    {
        text = new std::string(input_text);
    }
    Note(const Note& other) 
    {
		text = new std::string(*other.text);
	}	
    ~Note() 
    {
		delete text;
		text = nullptr; 
	}
    void display()
    {
		if (text != nullptr) {
			std::cout << *text << std::endl;
		}
	}
};

//////////////////////////////MAIN/////////////////////////////
int main()
{
    Note firstNote("This is a test.");
	Note secondNote = firstNote;

	firstNote.display();
	secondNote.display();

	return 0;
}
//////////////////////////////MAIN/////////////////////////////
