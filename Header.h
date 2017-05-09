#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

#define ship (char)219
#define ship_death (char)176
#define ship_ran (char)178
#define table_size 10
#define sea '~'
#define turn 'x'
#define s_4 '4'
#define s_3 '3'
#define s_2 '2'
#define s_1 '1'
#define popav 30
#define promax -8
#define KILL 100

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

struct Position
{
	short x_pos;
	short y_pos;
};

struct Player
{
	char name[50];
	int score = 0;
	char win_no[20];

};

/// Ships Placer ///
void ships_placer(char **field);
int write_temp_field(char **temp, char **field_my, bool choice);
// From File --- 
int rewrite_table(char **field_my);
/// ---- END ---- ////

// Menu //
void SetColor(int text, int background);
void menu(char **field_my, char **temp_my, char **field_pc, char **temp_pc);
void go(int x, char **field_my, char **temp_my, char **field_pc, char **temp_pc); // Choice of menu
// --- END --- ///
// Turns and Print
int turns(char **temp, char **field, Position pos);
void print_table(char **temp_my, char **field_my);
void find_way(char **field, short x, short y, char **temp);
void bort_print(short x, short y, char **temp, char **field);
// --- END --- //
// Coordinates //
void keyword(short x, short y);
void pc_cord(short x, short y);
void GotoXY(short X, short Y);
// -- END --- //
// -- Batle -- //
void batle(char **field_my, char **temp_my, char **field_pc, char **temp_pc);
// Score in File //
void print_stat();
void write_stat();
