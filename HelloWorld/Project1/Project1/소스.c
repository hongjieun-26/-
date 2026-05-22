#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++) {
		char ymd[10];
		scanf("%s", ymd);
		printf("%s\n", ymd);

		char year[10], month[10], day[10];
		int i;
		for (i = 0; i < 4; i++) {
			year[i] = ymd[i];
			year[4] = '\0';
		}
		for (i = 0; i < 2; i++) {
			month[i] = ymd[i + 4];
			month[2] = '\0';
		}
		for (i = 0; i < 2; i++) {
			day[i] = ymd[i + 6];
			day[2] = '\0';
		}
		int day_int = (int)(day[0] - 48) * 10 + (int)(day[1] - 48);
		int month_int = (int)(month[0] - 48) * 10 + (int)(month[1] - 48);
		//printf("%d\n", day_int);
		int check = 1;
		//printf("%s %s %s\n", year, month, day);
		if (month_int == 1 || month_int == 3 || month_int == 5 || month_int == 7 ||
			month_int == 8 || month_int == 10 || month_int == 12) {
			if (day_int < 1 || day_int > 31) check = 0;
		}
		else if (month_int == 2) {
			if (day_int < 1 || day_int > 28) check = 0;
		}
		else {
			if (day_int < 1 || day_int > 30) check = 0;
		}
		if (month_int < 1 || month_int > 12) check = 0;
		if (check == 0) printf("#%d %d\n", test_case, -1);
		else {
			char ymd_ret[20];
			for (i = 0; i < 4; i++) ymd_ret[i] = year[i];
			ymd_ret[4] = '\/';
			for (i = 0; i < 2; i++) ymd_ret[i + 5] = month[i];
			ymd_ret[7] = '\/';
			for (i = 0; i < 2; i++) ymd_ret[i + 8] = day[i];
			ymd_ret[10] = '\0';
			printf("#%d %s\n", test_case, ymd_ret);
		}
	}
	return 0; 

}
