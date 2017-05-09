#pragma once
#include "Header.h"
#include <fstream>

COORD pos = {3,3};
Position cord;
Player score[255];

short ships_my = 20;
short ships_pc = 20;

//// Coordinates //
void GotoXY(short X, short Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void keyword(short x, short y) {

	while (true)
	{
		char c = 0;

		while (c != 13) //завершение программы по нажатию клавиши ENTER
		{ 
			c = _getch();
			switch (c) {
			case 75:
			{
				if (pos.X < 3)
				{
					pos.X; 
				}
				else
				{
					pos.X--;
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				break;
			}
			case 77:
			{
				if (pos.X > 10)
				{
					pos.X;
				}
				else
				{
					pos.X++;
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				break;
			}
			case 72:
			{
				if (pos.Y < 3)
				{
					pos.Y;
				}
				else
				{
					pos.Y--;
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				break;
			}

			case 80:
			{
				if (pos.Y > 10)
				{
					pos.Y;
				}
				else
				{
					pos.Y++;
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				break;
			} 
			case 13:
			{
				cord.x_pos = pos.X - 2;
				cord.y_pos = pos.Y - 2;
				break;
			}
			}

		}
		break;
	}
}
void pc_cord(short x, short y) {

	cord.x_pos = rand() % 9;
	cord.y_pos = rand() % 9;

}
/// Print/Reprint table ///
void print_table(char **temp_my, char **temp_pc) {

	system("cls");
	cout << "  ABVGDEJZKL" << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < table_size; i++)
	{
		cout << i << " ";
		for (int j = 0; j < table_size ; j++)
		{
			cout << temp_my[i][j];
		}
		cout << endl;
	}
	cout << "  ABVGDEJZKL" << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < table_size; i++)
	{
		cout << i << " ";
		for (int j = 0; j < table_size; j++)
		{
			cout << temp_pc[i][j];
		}
		cout << endl;
	}
}
/// Turns ///
int turns(char **temp, char **field, Position pos) {

	if (isdigit(field[cord.y_pos][cord.x_pos]))
	{
		if (atoi(&field[cord.y_pos][cord.x_pos]) == 1)
		{
			bort_print(cord.x_pos, cord.y_pos, temp, field);
		}
		else
		{
			temp[cord.y_pos][cord.x_pos] = ship_ran;
			find_way(field, cord.x_pos, cord.y_pos, temp);
		}
		return 1;
	}
	else
	{
		temp[cord.y_pos][cord.x_pos] = turn;
		return 0;
	}

}
void batle(char **field_my, char **temp_my, char **field_pc, char **temp_pc) {
	cout << "Enter Your NikName: ";
	cin >> score[0].name;
	short Q;
	print_table(temp_my, temp_pc);

	while (true)
	{
		do
		{
			do
			{
				keyword(cord.y_pos, cord.x_pos);

			} while (temp_my[cord.y_pos][cord.x_pos] == turn || temp_my[cord.y_pos][cord.x_pos] == ship_ran || temp_my[cord.y_pos][cord.x_pos] == ship_death);
			Q = turns(temp_my, field_pc, cord);
			Q ? score[0].score += popav, ships_pc-- : score[0].score += promax, ships_pc;
			print_table(temp_my, temp_pc);

		} while (Q && ships_pc != 0);
		do
		{
			do
			{
				pc_cord(cord.y_pos, cord.x_pos);

			} while (temp_pc[cord.y_pos][cord.x_pos] == turn || temp_pc[cord.y_pos][cord.x_pos] == ship_ran || temp_pc[cord.y_pos][cord.x_pos] == ship_death);
			Q = turns(temp_pc, field_my, cord);
			if (temp_pc[cord.y_pos][cord.x_pos] == sea)
			{
				print_table(temp_my, temp_pc);

			}
			Q ? ships_my-- : ships_my;

		} while (Q && ships_my != 0);

		if (ships_pc == 0 || ships_my == 0)
		{
			write_stat();

			(ships_pc < ships_my) ? cout << "	Player Win: -	" << score[0].name << "  " : cout << "	PC Win	-	";
			cout << score[0].score << endl;
			cin.clear();
			getch();
			ships_my = 20;
			ships_pc = 20;
			//menu(field_my, temp_my, field_pc, temp_pc);
			break;
		}
	}

}
/// Set Fields ///
int write_temp_field(char **temp, char **field_my, bool choice) {
	if (choice)
	{
		for (int i = 0; i < table_size; i++)
		{
			temp[i] = new char[table_size + 1];
			for (short j = 0; j < table_size; j++)
			{
				temp[i][j] = sea;
			}
		}
		return **temp;
	}
	else
	{
		for (int i = 0; i < table_size; i++)
		{
			temp[i] = new char[table_size + 1];
			for (short j = 0; j < table_size; j++)
			{
				if (isdigit(field_my[i][j]))
				{
					temp[i][j] = ship;
				}
				else
				{
					temp[i][j] = sea;
				}
				
			}
		}
		return **temp;
	}
	
}
int bort(short x, short y, char **field) {

	bool a = true;

	if (x + 1 < 10)
	{
		if (isdigit(field[y][x + 1]))
		{
			a = false;
			return a;
		}

	}
	if (x - 1 > -1)
	{
		if (isdigit(field[y][x - 1]))
		{
			a = false;
			return a;
		}

	}
	if (y - 1 > -1)
	{
		if (isdigit(field[y - 1][x]))
		{
			a = false;
			return a;
		}
	}
	if (y + 1 < 10)
	{
		if (isdigit(field[y + 1][x]))
		{
			a = false;
			return a;
		}
	}
	if (y - 1 > -1 && x + 1 < 10)
	{
		if (isdigit(field[y - 1][x + 1]))
		{
			a = false;
			return a;
		}
	}
	if (y - 1 > -1 && x - 1 > 0)
	{
		if (isdigit(field[y - 1][x - 1]))
		{
			a = false;
			return a;
		}
	}
	if (y + 1 < 10 && x + 1 < 10)
	{
		if (isdigit(field[y + 1][x + 1]))
		{
			a = false;
			return a;
		}
	}
	if (y + 1 < 10 && x - 1 > -1)
	{
		if (isdigit(field[y + 1][x - 1]))
		{
			a = false;
			return a;
		}
	}


	return a;

}
int perevirka_4(short x, short y, char **field, short ship_value) {

	bool a = false;
	short up = 1, down = 3, right = 2, left = 4;

	for (short j = 0; j < ship_value; j++)
	{
		if (x + ship_value < 10 && !isdigit(field[y][x + j]))
		{
			if (isdigit(field[y][x + j]))
			{
				a = false;
				break;
			}
			a = bort(x + j, y, field);
			if (!a)
			{
				break;
			}
		}
	}
	if (a)
	{
		return right;
	}
	for (short j = 0; j < ship_value; j++)
	{
		if (y + ship_value < 10 && !isdigit(field[y + j][x]))
		{
			if (isdigit(field[y + j][x]))
			{
				a = false;
				break;

			}
			a = bort(x, y + j, field);
			if (!a)
			{
				break;
			}
		}
	}

	if (a)
	{
		return down;
	}

	for (short j = 0; j < ship_value; j++)
	{

		if (y - ship_value > 0 && !isdigit(field[y - j][x]) == field[y - j][x])
		{
			if (isdigit(field[y - j][x]))
			{
				a = false;
				break;

			}
			a = bort(x, y - j, field);
			if (!a)
			{
				break;
			}
		}
	}

	if (a)
	{
		return left;
	}

	for (short j = 0; j < ship_value; j++)
	{
		//x - j == -1 ? a = false : a;
		if (x - ship_value > 0 && !isdigit(field[y][x - j]) == field[y][x - j])
		{
			if (isdigit(field[y][x - j]))
			{
				a = false;
				break;
			}
			a = bort(x - j, y, field);
			if (!a)
			{
				break;
			}
		}

	}

	if (a)
	{
		return up;
	}

	return 5;
}
void ships_placer(char **field) {

	short top = 1, down = 4, x, y, place, ship_value = 4;
	char shiper;

	for (short i = 0; i < table_size; i++)
	{
		field[i] = new char[table_size];
		for (short j = 0; j < table_size; j++)
		{
			field[i][j] = sea;
		}
	}

	for (short i = 0; i < 4; i++)
	{
		//////
		for (short j = -1; j < i; j++)
		{
			//////
		begin:
			x = rand() % 9;
			y = rand() % 9;
			shiper = i == 0 ? s_4 : i == 1 ? s_3 : i == 2 ? s_2 : s_1;
			if (!isdigit(field[y][x]))
			{
				place = perevirka_4(x, y, field, ship_value);
			}
			else
			{
				goto begin;
			}
			switch (place)
			{
			case 1: {

				for (int l = 0; l < ship_value; l++)
				{
					field[y - l][x] = shiper;

				}

				break;
			}
			case 2: {

				for (int l = 0; l < ship_value; l++)
				{
					field[y][x + l] = shiper;

				}


				break;
			}
			case 3: {

				for (int l = 0; l < ship_value; l++)
				{
					field[y + l][x] = shiper;

				}

				break;
			}
			case 4: {

				for (int l = 0; l < ship_value; l++)
				{
					field[y][x - l] = shiper;

				}

				break;
			}
			case 5: {
				goto begin;

				break;
			}
			}


			///////

		}


		//////
		ship_value--;

	}

}
//// From File!!!!
int rewrite_table(char **field_my) {

	ifstream field("fields/1.txt");

	if (!field.is_open())
	{
		cout << "Not such file in base!!!" << endl;
		return 0;
	}
	char line;

	for (unsigned i = 0; i < table_size; i++)
	{
		field_my[i] = new char[table_size + 1];
	}
	field.get(line);
	while (!field.eof())
	{
		for (unsigned i = 0; i < 10; i++)
		{
			for (unsigned j = 0; j < table_size + 1; j++)
			{
				/*if (!isdigit(line))
				{
					field_my[i][j] = sea;
				}
				else
				{
					field_my[i][j] = ship;
				}*/
				field_my[i][j] = line;
				field.get(line);

			}

		}

	}

	return **field_my;
}
// -- Print Misle above ships -- //
int way(char **field, short x, short y) {
	short up = 1, right = 2;
	if (x + 1 < 10 && isdigit(field[y][x + 1]))
	{
		return right;
	}
	if (x - 1 > -1 && isdigit(field[y][x - 1]))
	{
		return right;
	}
	if (y + 1 < 10 && isdigit(field[y + 1][x]))
	{
		return up;
	}
	if (y - 1 > -1 && isdigit(field[y - 1][x]))
	{
		return up;
	}

}
void bort_print(short x, short y, char **temp, char **field) {

	if (x + 1 < 10 && !isdigit(field[y][x + 1]))
	{
		temp[y][x + 1] = turn;
	}
	if (x - 1 > -1 && !isdigit(field[y][x - 1]))
	{
		temp[y][x - 1] = turn;
	}
	if (y - 1 > -1 && !isdigit(field[y - 1][x]))
	{
		temp[y - 1][x] = turn;
	}
	if (y + 1 < 10 && !isdigit(field[y + 1][x]))
	{
		temp[y + 1][x] = turn;
	}
	if (y - 1 > -1 && x + 1 < 10 && !isdigit(field[y - 1][x + 1]))
	{
		temp[y - 1][x + 1] = turn;
	}
	if (y - 1 > -1 && x - 1 > -1 && !isdigit(field[y - 1][x - 1]))
	{
		temp[y - 1][x - 1] = turn;
	}
	if (y + 1 < 10 && x + 1 < 10 && !isdigit(field[y + 1][x + 1]))
	{
		temp[y + 1][x + 1] = turn;
	}
	if (y + 1 < 10 && x - 1 > -1 && !isdigit(field[y + 1][x - 1]))
	{
		temp[y + 1][x - 1] = turn;
	}
	temp[y][x] = ship_death;
	score[0].score += KILL;

}
void find_way(char **field, short x, short y, char **temp) {
	short in_way = way(field, x, y), value;
	short left = 2, up = 1, i = 0;
	if (in_way == 2 && x + 1 < 10)
	{
		do
		{
			left = x + i;
		} while (++i, x + i < 10 && isdigit(field[y][x + i]));
		value = atoi(&field[y][left]);
		for (short i = 0; i < value; i++)
		{

			if (isdigit(field[y][left - i]) && temp[y][left - i] != ship_ran)
			{
				return;
			}
			else if (i == value - 1)
			{
				for (int j = 0; j < value; j++)
				{
					bort_print(left - j, y, temp, field);
				}
			}

		}
		return;

	}
	i = 0;
	if (in_way == 1 && y + 1 < 10)
	{
		do
		{
			up = y + i;

		} while (++i, y + i < 10 && isdigit(field[y + i][x]));
		value = atoi(&field[up][x]);
		for (short i = 0; i < value; i++)
		{
			if (isdigit(field[up - i][x]) && temp[up - i][x] != ship_ran)
			{
				return;
			}
			else if (i == value - 1)
			{
				for (int j = 0; j < value; j++)
				{
					bort_print(x, up - j, temp, field);
				}
			}

		}
		return;
	}
}
// -- END --- //
void write_stat() {

	ofstream file;
	file.open("p_scores.dat", ios::app , ios_base::binary);

	if (!file.is_open())
	{
		cout << "File not Open - Stat not write" << endl;
		return;
	}
	file.write(score[0].name, strlen(score[0].name));
	file.write("|", sizeof(char));
	file.write((ships_pc < ships_my) ? "1|" : "0|", strlen((ships_pc < ships_my) ? "1|" : "0|"));
	file << score[0].score;
	file.write("\n", sizeof(char));
	file.close();

}
void print_stat() {

	ifstream file("p_scores.dat", ios::binary);
	if (!file.is_open())
	{
		cout << "File not Open - Stat not Read" << endl;
		return;
	}
	system("cls");

	for (int i = 0; !file.eof(); i++)
	{
		file.getline(score[i].name, 50, '|');
		file.getline(score[i].win_no, 55, '|');
		file >> score[i].score;
	


		if (!file.eof())
		{
			cout << "	+	Player - ";
			SetColor(6, 0); cout << score[i].name; SetColor(15, 0); 
			cout << "  -  "; 
			(atoi(score[i].win_no) == 0) ? SetColor(4, 0) : SetColor(2, 0);
			cout << ((atoi(score[i].win_no) == 0) ? "Lose" : "Win");
			SetColor(15, 0);
			cout << " - Score: " << score[i].score << endl;

		}
		file.get();
		file.get();
	}
	SetColor(8, 0);  cout << "		+	 --- +Press any key to kontinue+ ---" << endl; SetColor(15, 0);
	file.close();


}
