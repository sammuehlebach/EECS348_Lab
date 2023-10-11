#include <stdio.h>

#define MONTHS 12


void printReport(double sales[]) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022:\n");
    printf("Month       Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]);
    }
}


double minSales(double sales[]) {
    int min = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < sales[min]) {
            min = i;
        }
    }
    return min;
}


double maxSales(double sales[]) {
    int max = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] > sales[max]) {
        max = i;
        }
    }
    return max;
}


double averageSales(double sales[]) {
    double sum = 0;
    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];
    }
    return sum/MONTHS;
}


void printHighLowSales(double sales[]) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    char *orderedMonths[MONTHS];
    double orderedSales[MONTHS];


    for (int i = 0; i < MONTHS; i++) {
        orderedSales[i] = sales[i];
        orderedMonths[i] = months[i];
    }   


    for (int i = 0; i < MONTHS; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (orderedSales[j] > orderedSales[i]) {
            double temp = orderedSales[i];
            orderedSales[i] = orderedSales[j];
            orderedSales[j] = temp;


            char *tempMonth = orderedMonths[i];
            orderedMonths[i] = orderedMonths[j];
            orderedMonths[j] = tempMonth;
            }
        }
    }


    printf("Month       Sales\n");
    for(int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", orderedMonths[i], orderedSales[i]);
    }
}


void printSixMonthAverage(double sales[]) {
    char *months[MONTHS] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2lf\n", months[i], months[i + 5], sum / 6.0);
    }
}


int main() {
    FILE *file = fopen("data.txt", "r");

    double salesCount[MONTHS];
    char *months[MONTHS] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < MONTHS; i++) {

        fscanf(file, "%lf", &salesCount[i]);
    }
    fclose(file);


    int min = minSales(salesCount);
    int max = maxSales(salesCount);


    printReport(salesCount);
    printf("\n");
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", salesCount[min], months[min]);
    printf("Maximum sales: $%.2f (%s)\n", salesCount[max], months[max]);
    printf("Average sales: $%.2f\n", averageSales(salesCount));
    printf("\n");
    printf("Six-Month Moving Average Report:\n");
    printSixMonthAverage(salesCount);
    printf("\n");


    printf("Sales Report (Highest to Lowest):\n");
    printHighLowSales(salesCount);

    printf("\n");


    return 0;
}
