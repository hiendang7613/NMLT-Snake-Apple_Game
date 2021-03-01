#include "Control.h"

int input() {
	char c;
	c= getch();
	if (c == 27) { return 5; }
	else if (c == 13) { return 0; }
	else if (c == 0) {
		c = getch();
		if (c == 80) { return 4; }
		else if (c == 72) { return 2; }
		else if (c == 75) { return 3; }
		else if (c == 77) { return 1; }
	}
	return -1;
}