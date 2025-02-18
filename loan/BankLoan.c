# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
#include <assert.h>



typedef struct Loan{
  double amount_borrowed;
  double numbers_loan;
  double rates_interest;
  double monthly_payment;
  double amount_repayment;
  double time_repayment;
} Loan;


Loan newLoan( double m, double l, double r, double p ){
  Loan loan = {m,l,r,p, 0, 0};
  return loan;
}


void calculatePayBack (Loan* loan){
  double value = loan[0].amount_borrowed;
  double amount_repayment = 0;
    for(int i =0; i< value; i++){
       value -= loan[i].monthly_payment ;
       double rates = loan[i].amount_borrowed * loan[i].rates_interest;
       printf("%f\n", rates);
       double roundedDown = floor(rates);
       // CALCULATATION REPAYMENT
       loan[i].amount_repayment +=  roundedDown +  loan[i].monthly_payment;
       printf("%f\n",roundedDown);
       value += roundedDown;
       printf("%f\n",value);
    }
}

void recoverInput(){
  double m;
  double l;
  double r;
  double p;
  printf("Write the amount of the loan and the proposal\n");
  scanf("%lf %lf", &m, &l);
  Loan* ln = malloc(sizeof(Loan)*l);
  for(int i =0; i< l; i++){
    printf("Write the interest rate and the monthly payment\n");
    scanf("%lf %lf", &r, &p);
    ln[i] = newLoan(m, l, r, p);
    // CALCUALTE PAYBACK
  }
  calculatePayBack(ln);
  free(ln);
}



/*
bool calculationPayOff(double value, double rates,double pay ){
  
}


*/


int main(void){
  recoverInput();
 

  }

  