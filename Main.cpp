#include "Header.h"
int Repeat();

int main()
{
	setlocale(LC_ALL, "Russian");

	Date name;
	ImputDay(name);
	Cheсk(name);
	Output(name);
	Repeat();
}

int Repeat()
{
	char answer;
	std::cout << "\nЖелаете повторить? (y/n) - ";
	std::cin >> answer;
	std::cout << '\n';

	assert(answer == 'y' || answer == 'n');

	if (answer == 'y') return main();
	else
	{
		std::cout << "Спасибо за использование программы \n";
		return 0;
	}
}