#include<stdio.h>
#include<stdbool.h>




void death_if (){
    printf("Enter a value \n");
    int input_user;
    scanf("%d" , &input_user);
    if (input_user = 2)
        if (input_user > 10)
        printf("the number %d is major than 10 ", input_user );
        // IDENTATION IN C DOES NOT MATTER
    else
        printf("the number %d is minor than 2 ", input_user );
}


int sum_up (int n){
    return n +1;
}

int main (){
    
int n = 10;
printf("%d\n",sum_up(n));
printf("%d\n",n);
// division and moltiplication has the same order
int order = 20/10 *10;
// division and moltiplication has the same order
printf("%d\n", order);
// pass another types of value it will generates 0
int literal_value;
scanf("%d", &literal_value);
printf("%d", literal_value);

bool funny = true;
int c = 0; // in c is false
if(c != 2){
    printf("OK");
}



int i_val = 12;
double d_val = 1.4;
int one = 1;
double d_one = 1.0;
double resultsd = (double) i_val / 8 * 4 - ((int) d_val) * 3;
death_if();
int verify = 5/2 ;
printf("%d", verify);
int value_one , value_two;
value_one = 3.0 * 2.5; // 7
value_two = 2.5 * 3.5; // 8
double result = value_one  * value_two * 0.99;
printf("inplicit casting %lf\n,", result);
int value_one_exp = 3;
int  value_two_exp  = 3;
double explicit = (double)value_one_exp * (double) value_two_exp;
printf("explicit casting %lf\n,", explicit);
return 0;

}