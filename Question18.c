#include<stdio.h>
int main(){
    int percentage;
    printf("Enter your percentage:");
scanf("%d",&percentage);

if (percentage >=90 && percentage <= 100)
printf("grade: A\n");
    else if (percentage >= 80 && percentage <= 89)
    printf("grade:B\n");
    else if (percentage >= 70 && percentage <= 79)
    printf("grade:C\n");
    else if (percentage >= 60 && percentage <= 69)
    printf("grade:D\n");
    else if (percentage >= 0 && percentage <= 60)
printf("grade:F\n");
else
printf("Invalid percentage\n");
return 0;
}
