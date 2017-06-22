#include "Header.h"


char* DayName[] = { "�������" , "�����������", "�����������", "�������", "�����", "�������", "�������" };


void ImputDay(Date &_ptr)
{
	std::cout << "������� ����: ";
	std::cin >> _ptr.Day;

	if (_ptr.Day > 0 && _ptr.Day <= 31)	ImputMonth(_ptr);

	else
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n������ ����� ���. ���������� ������� ����� �� 1 �� 31\n";
		return ImputDay(_ptr);
	}
}

void ImputMonth(Date &_ptr)
{	
	
	std::cout << "������� �����: ";
	std::cin >> _ptr.Month;
	
	if (_ptr.Month < 0 || _ptr.Month > 12)
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "\n������ ����� ������. ����������, ������� ����� �� 1 �� 12\n";
				return ImputMonth(_ptr);
			}
	
	else if ((_ptr.Month == 4 || _ptr.Month == 6 || _ptr.Month == 9 || _ptr.Month == 11) && _ptr.Day >30)
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "\n�������� ���� ���������� ���� �� ������������� ������� ������. ���������� ������ ���� ������\n";
				return ImputDay(_ptr);
			}
	else if (_ptr.Month == 2 && _ptr.Day > 29)
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "\n�������� ���� ���������� ���� �� ������������� ������� ������. ���������� ������ ���� ������\n";
				return ImputDay(_ptr);
			}
	
	ImputYear(_ptr);
}

void ImputYear(Date &_ptr)
{
	std::cout << "������� ���: ";
	std::cin >> _ptr.Year;
	
	if (!(_ptr.Year > 0))
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n������ ����� ����. ����������, ������� ����� ������ ����.\n";
		return ImputYear(_ptr);
	}

	if (_ptr.Month == 2 && !(_ptr.Year % 4 == 0 && (_ptr.Year % 100 != 0 || _ptr.Year % 400 == 0)) && _ptr.Day > 28)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n������ ��� �������� �� ����������, � ������ � �������� ���� ������ �� ����� ���� ����� 28 ����.\n����������, ������� ������ �����, ���� ���.\n";
		return ImputMonth(_ptr);
	}
		
}

void Che�k(Date _ptr)
{
	
	assert(_ptr.Day > 0 && _ptr.Day <= 31 && _ptr.Month>0 && _ptr.Month <= 12 && _ptr.Year>0);

	if (_ptr.Month == 4 || _ptr.Month == 6 || _ptr.Month == 9 || _ptr.Month == 11)
		assert(_ptr.Day <= 30);
	
	if ((_ptr.Month == 2))
	{
		if (_ptr.Year % 4 == 0 && (_ptr.Year % 100 != 0 || _ptr.Year % 400 == 0))
			assert(_ptr.Day <= 29);
		else
			assert(_ptr.Day <= 28);
	}
	
}

void Output(Date _ptr)
{
	std::cout << "\n�� �������������� ��������� ��� - " << DayName[GregorianDay(_ptr)] ;
	std::cout << "\n�� ���������� ��������� ��� - " << DayName[JulianDay(_ptr)] ;
	std::cout << "\n���� �������: ";
		FindZodiac(_ptr);
		std::cout << '\n';

}

int JulianDay(Date _ptr)
{
	return (_ptr.Day + (13 * (_ptr.Month + 1) / 5) + _ptr.Year % 100 + (_ptr.Year % 100) / 4 + 5 + 6 * (_ptr.Year / 100)) % 7;
}

int GregorianDay(Date _ptr)
{
	int q = (_ptr.Year % 100);
	int w = (_ptr.Year / 100);
	int r = (13 * (_ptr.Month + 1) / 5);
	int rez = (_ptr.Day + r + q + q / 4 + w / 4 + 5 * w);

	return rez %= 7;
}

void FindZodiac(Date _ptr)
{
	if (_ptr.Month == 13 || _ptr.Month == 14)
	{
		_ptr.Month -= 12;
		_ptr.Year++;
	}

	if ((_ptr.Month == 3 && _ptr.Day >= 21) || (_ptr.Month == 4 && _ptr.Day <= 19))
		std::cout << "����";
	else if ((_ptr.Month == 4 && _ptr.Day >= 20) || (_ptr.Month == 5 && _ptr.Day <= 20))
		std::cout << "�����";
	else if ((_ptr.Month == 5 && _ptr.Day >= 21) || (_ptr.Month == 6 && _ptr.Day <= 20))
		std::cout << "��������";
	else if ((_ptr.Month == 6 && _ptr.Day >= 21) || (_ptr.Month == 7 && _ptr.Day <= 22))
		std::cout << "���";
	else if ((_ptr.Month == 7 && _ptr.Day >= 23) || (_ptr.Month == 8 && _ptr.Day <= 22))
		std::cout << "���";
	else if ((_ptr.Month == 8 && _ptr.Day >= 23) || (_ptr.Month == 9 && _ptr.Day <= 22))
		std::cout << "����";
	else if ((_ptr.Month == 9 && _ptr.Day >= 23) || (_ptr.Month == 10 && _ptr.Day <= 22))
		std::cout << "����";
	else if ((_ptr.Month == 10 && _ptr.Day >= 23) || (_ptr.Month == 11 && _ptr.Day <= 21))
		std::cout << "��������";
	else if ((_ptr.Month == 11 && _ptr.Day >= 22) || (_ptr.Month == 12 && _ptr.Day <= 21))
		std::cout << "�������";
	else if ((_ptr.Month == 12 && _ptr.Day >= 22) || (_ptr.Month == 1 && _ptr.Day <= 19))
		std::cout << "�������";
	else if ((_ptr.Month == 1 && _ptr.Day >= 20) || (_ptr.Month == 2 && _ptr.Day <= 18))
		std::cout << "�������";
	else if ((_ptr.Month == 2 && _ptr.Day >= 19) || (_ptr.Month == 3 && _ptr.Day <= 20))
		std::cout << "����";
}

