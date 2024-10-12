/* 
 * Name: Lillian Brooks-Kanost
 * KU ID: 3115848
 * Class: EECS 348 Friday 4pm Lab
 * Lab 5
 * Given 12 monthly sales figures in an input file, the following reports are generated:
 * Monthly Sales Report, Sales Summary Report, Six-Month Moving Average Report, Sales Report (highest to lowest)
 * These reports are then printed to the terminal.
 */

#include <stdio.h>
#include <stdlib.h>
void monthly_report(float monthly_sales[12],char *months[12]);
void sales_summary_report(float monthly_sales[12],char *months[12]);
void six_month_average(float monthly_sales[12],char *months[12]);
void sales_report_sorted(float monthly_sales[12],char *months[12]);

int main() {
	/* reads a user-inputted file, then converts the str to floats and calls other functions */
	char file_name[30];
	printf("Enter the input file name: \n");
	scanf("%s", file_name);
	FILE* ptr;
	ptr = fopen(file_name, "r");
	if (ptr == NULL) {
		printf("Invalid file name; file could not be accessed \n");	
		return 1;
	}
	char single_line[30];
	float monthly_sales[12];
	int x = 0;
	while (x < 12 && fgets(single_line, sizeof(single_line), ptr)) {
        	monthly_sales[x] = atof(single_line);
        	x++;
    	}
	fclose(ptr);
	char *months[12] = {"January   ", "February  ", "March     ", "April     ", "May       ", "June      ", "July      ", "August    ", "September ", "October   ", "November  ", "December  "}; 
	monthly_report(monthly_sales, months);
	sales_summary_report(monthly_sales, months);
	six_month_average(monthly_sales, months);
	sales_report_sorted(monthly_sales, months);
	return 0;
	
}

void monthly_report(float monthly_sales[12], char *months[12]) {
	/* prints a sale report for each month */
	printf("\nMonthly Sales Report for 2024\n");
	printf("Month     Sales\n");
	for (int x = 0; x < 12; x++) {
		printf("%s%.2f\n", months[x], monthly_sales[x]);
	}
}

void sales_summary_report(float monthly_sales[12], char *months[12] ) {
	/* prints a summary report including the maximum sales month, minimum sales month,
	 * and average between all months 
	 */
	printf("\nSales summary report: \n");
	float minimum = -100;
	float maximum = -100;
	int min_month = 0;
	int max_month = 0;
	float average = 0;
	for (int i = 0; i < 12; i ++) {
		if (monthly_sales[i] < minimum || minimum == -100) {
			minimum = monthly_sales[i];
			min_month = i;
		}	
		if (monthly_sales[i] > maximum || maximum == -100) {
			maximum = monthly_sales[i];
			max_month = i;
		}
		average += monthly_sales[i];
	}	
	average = average / 12;
	printf("Minimum sales: %.2f (          %s)\n", minimum, months[min_month]);
	printf("Maximum sales: %.2f (          %s) \n", maximum, months[max_month]);
	printf("Average sales: %.2f\n", average);
}

void six_month_average(float monthly_sales[12], char *months[12]) {
	/* prints a six-month moving average report, starting with Jan-July and ending with July-Dec */
	printf("\nSix-month moving average report: \n");
	int month_one = 0;
	int month_six = 5;
	while (month_six < 12) {
		float average = 0;
		for (int i = month_one; i < month_six + 1; i++) {
			average += monthly_sales[i];
		}
		average = average / 6;
		printf("%s-          %s%.2f\n", months[month_one], months[month_six], average);
		month_one ++;
		month_six ++;
		
	}
}

void sales_report_sorted(float monthly_sales[12], char *months[12]) {
	/* prints a sales report for each month, sorted by sales high-low */
	printf("\nSales report (highest to lowest): \n");
	printf("Month     Sales\n");
	for (int i = 0; i < 12; i++) {
		float maximum = 0;
		int max_month = 0;
		for (int j = 0; j < 12; j++) {
			if (maximum < monthly_sales[j]) {
				maximum = monthly_sales[j];
				max_month = j;
			}
		}
		printf("%s$%.2f\n", months[max_month], maximum);
		monthly_sales[max_month] = 0;
	}
}