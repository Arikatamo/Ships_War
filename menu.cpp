#include "Header.h"
HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int m_pos = 0;          // позиция меню
int max_pos = 5;        // максимальная позиция меню
short set = 0;
void SetColor(int text, int background) // устанавливаем цвет
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 5) | text));
}
void choice(char **field_my, char **temp_my, char **field_pc, char **temp_pc);
void menu(char **field_my, char **temp_my, char **field_pc, char **temp_pc)
{	
	system("cls"); // очистить экран
	if (m_pos == 0)
	{
		SetColor(6, 0); cout << " + Start\n"; SetColor(15, 0);
		cout << "   Statistics\n";
		cout << "   Set Ships Random\n";
		cout << "   Set Ships From File\n";
		cout << "   Exit\n";
		choice(field_my, temp_my, field_pc, temp_pc);
	}
	if (m_pos == 1)
	{
		cout << "   Start\n"; 
		SetColor(6, 0); cout << " + Statistics\n"; SetColor(15, 0);
		cout << "   Set Ships Random\n";
		cout << "   Set Ships From File\n";
		cout << "   Exit\n";
		choice(field_my, temp_my, field_pc, temp_pc);
	}
	if (m_pos == 2)
	{
		cout << "   Start\n";
		cout << "   Statistics\n";
		SetColor(6, 0); cout << " + Set Ships Random\n"; SetColor(15, 0);
		cout << "   Set Ships From File\n";
		cout << "   Exit\n";
		choice(field_my, temp_my, field_pc, temp_pc);
	}
	if (m_pos == 3)
	{
		cout << "   Start\n";
		cout << "   Statistics\n"; 
		cout << "   Set Ships Random\n";
		SetColor(6, 0); cout << " + Set Ships From File\n"; SetColor(15, 0);
		cout << "   Exit\n";
		choice(field_my, temp_my, field_pc, temp_pc);
	}
	if (m_pos == 4)
	{
		cout << "   Start\n"; SetColor(15, 0);
		cout << "   Statistics\n";
		cout << "   Set Ships Random\n";
		cout << "   Set Ships From File\n";
		SetColor(6, 0); cout << " + Exit\n"; SetColor(15, 0);
		choice(field_my, temp_my, field_pc, temp_pc);
	}
}
void choice(char **field_my, char **temp_my, char **field_pc, char **temp_pc)
{
l:
	int ch = _getch(); // считываем значение нажатой клавиши
	switch (ch)
	{
	case 80: // вниз
		if (m_pos + 1 < max_pos) ++m_pos;
		menu(field_my, temp_my, field_pc, temp_pc);
		break;
	case 72: // вверх
		if (m_pos - 1 >= 0) --m_pos;
		menu(field_my, temp_my, field_pc, temp_pc);
		break;
	case 13: // Enter
		go(m_pos, field_my, temp_my, field_pc, temp_pc);
		break;
	default:
		goto l;
	}
}
void go(int x, char **field_my, char **temp_my, char **field_pc, char **temp_pc) {

	if (x == 0) 
	{ 
		if (set == 0)
		{
		SetColor(4, 0); cout << "Ships not set" << endl; SetColor(15, 0);
		getch();
		menu(field_my, temp_my, field_pc, temp_pc);
		}
		batle(field_my, temp_my, field_pc, temp_pc);
		set = 0;
		menu(field_my, temp_my, field_pc, temp_pc);
	}
	if (x == 1)
	{
		print_stat(); 
		getch();
		menu(field_my, temp_my, field_pc, temp_pc);
	} 
	if (x == 2)
	{
		ships_placer(field_my);
		ships_placer(field_pc);
		write_temp_field(temp_pc, field_my, 0);
		write_temp_field(temp_my, field_my, 1);
		SetColor(2, 0); cout << " -- Ships Set" << endl;	SetColor(15, 0);
		set = 1;
		getch();
		menu(field_my, temp_my, field_pc, temp_pc);
	}
	if (x == 3)
	{
		rewrite_table(field_my);
		ships_placer(field_pc);
		write_temp_field(temp_pc, field_my, 0);
		write_temp_field(temp_my, field_my, 1);
		SetColor(2, 0); cout << " -- Ships Set" << endl;	SetColor(15, 0);
		set = 1;
		getch();
		menu(field_my, temp_my, field_pc, temp_pc);
	}
	if (x == 4)
	{
		cout << " -- CLOSE PROGRAM -- " << endl; exit(0);
	}
}
