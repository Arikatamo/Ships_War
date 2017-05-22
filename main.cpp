#include "Header.h"


int main() {
	srand(time(0));

	char **field_my = new char *[table_size];
	char **field_pc = new char *[table_size];
	char **temp_my = new char *[table_size];
	char **temp_pc = new char *[table_size];
	menu(field_my, temp_my, field_pc, temp_pc);


	return 0;

}
