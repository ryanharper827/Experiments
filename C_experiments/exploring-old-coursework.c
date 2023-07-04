#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PI 3.14159

void homework_title(int);
void homework_1();
void homework_2();
void homework_4();
int get_value();
void calc_results(int[], int);


int main()
{
    // Homework 1
    homework_1();
    getchar();

    // Homework 2
    homework_2();
    getchar();

    //homework 4
    homework_4();
    return 0;
}

void homework_title(int num){
    printf("=-= Homework %d =-=\n", num);
}

void homework_1(){
    homework_title(1);
    printf("Hello World\n");
}

void homework_2(){
    homework_title(2);
    printf("Pi is %.2lf\n", PI);
    int radius = 2 + 2;
    printf("2 plus 2 is %d\n", radius);
    float circumference = 2 * PI * radius;
    printf("The circumference of a circle with radius %d is %.4f.\n", radius, circumference);
}

void homework_4(){
    homework_title(4);
    srand(time(NULL)); //Sets random seed to time
    int size = 25;
    int arr[size];
    int i;
    for(i=0; i<size; i++){
        arr[i] = get_value();
    }
    calc_results(arr, size);
}

// Generates a random value between 60 and 100
int get_value(){
    return rand() % 41 + 60;
}

void calc_results(int arr[], int size){
    int min = arr[0];
    int max = 0;
    float avg;
    float total = 0;
    int i;
    printf("Temperature Conditions on October 9, 2015:\n"
    "Time of Day\tTemperature in degrees F\n");

    for(i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        total = total + arr[i];
        if(i == 24){
            printf("Midnight\t\t%d\n", arr[i]);
        }
        else{
            printf("%d\t\t\t%d\n", i, arr[i]);
        }
    }

    avg = total/size;

    printf("\nMaximum temperature for the day: %d Degrees F"
        "\nMinimum temperature for the day: %d Degrees F"
        "\nAverage temperature for the day: %.2f Degrees F", max, min, avg);
}