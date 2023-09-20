#include<stdio.h>

int calculateArea(int len, int bre); // function declaration



int main() {
    int len, bre;
    len = 2;
    bre = 4;
    printf("Enter two numbers:");
    scanf("%d%d", &len, &bre);
    int area = calculateArea(len, bre); // function call
    printf("%d", area);
    return 0; // 


int calculateArea(int len, int bre) { // function definition
    int area =  len * bre;
    return area;
}
