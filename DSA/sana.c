#include <stdio.h>
#define MAX 50

void q4(int a, int b)
{
    printf("After addition of %d and %d, the value is %d \n", a, b, (a + b));
    printf("After substraction of %d and %d, the value is %d \n", a, b, ((a > b) ? (a - b) : (b - a)));
    printf("After multiplication of %d and %d, the value is %d \n", a, b, a * b);
    printf("After division of %d and %d, the vale is %d \n", a, b, (a / b));
}

void q5(char name[], int roll, int sub1, int sub2, int sub3, int sub4)
{
    float marksTotal = (sub1 + sub2 + sub3 + sub4);
    double result = (((double)marksTotal) / 400 * 100.0);
    printf("The name of the student %s\nRoll no is %d\nShe secured the percentage mark %.2f %% \n", name, roll, result);
}

void q6(int a, int b, int c, int d, int e, int f, int g)
{
    printf("Sum is = %d \n", ((a + b / c * d - e) * (f - g)));
}

int main()
{
    int a1, b1;
    scanf("%d %d", &a1, &b1);
    q4(a1, b1);

    char name[MAX];
    int roll, sub1, sub2, sub3, sub4;
    printf("Enter the details of student\nEnter name, roll no, marks of Subject1, marks of Subject2, marks of Subject3, marks of Subject4\n");
    scanf("%s %d %d %d %d %d", name, &roll, &sub1, &sub2, &sub3, &sub4);
    q5(name, roll, sub1, sub2, sub3, sub4);

    int a, b, c, d, e, f, g;
    printf("Enter values of a,b,c,d,e,f and g : ");
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
    q6(a, b, c, d, e, f, g);

    return 0;
}