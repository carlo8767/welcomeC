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

void calculateTwo (Loan* loan){
    int index_loan =0;
    double values = loan[0].amount_borrowed;
    double month_pay = loan[0].monthly_payment;
    double add_interest = 0;
    int time = 0;
    double amount_return = 0;
    // ADD CHECK IF YOU CAN REPAY
    while(index_loan < loan[0].numbers_loan ){
      while(values > 0){
        // verify the difference
        if(values < month_pay){
            month_pay = values;
            values -= values;
        }
        else {
          values -= month_pay;
        }
        
        // CALCULATE INTEREST AND ADD AT VALUES
        add_interest =  values * (loan[index_loan].rates_interest/(double)100);
        values+= (int)add_interest;
       // CALCULATE THE  TIME
        time +=1;
        // CALCUALTE AMOUNT MONEY GIVE BACK NO KEEN INTEREST RETURN
       // amount_return += (int)add_interest+month_pay;
        if(values < month_pay){
          amount_return += month_pay;
        }
        else {
          amount_return = month_pay * time;
        }
        
      }
      index_loan+=1;
    }

  }

/*
void calculatePayBack (Loan* loan){
  double value_loan = loan[0].amount_borrowed;
  double time = 0;
  int index_loan = 0;
  double amount_repayment = 0;
  double number_proposal = loan[0].numbers_loan;
  while(index_loan < number_proposal){
    for(int i =0; i < value_loan ; i++){
      value_loan -=loan[index_loan].monthly_payment; 
       printf("the value after the payment is %lf\n",value_loan);
       double rates = value_loan * ((double)loan[index_loan].rates_interest/(double)100);
       printf("the rate is %lf\n", rates);
       double roundedDown = floor(rates);
       printf("the round is %lf\n", roundedDown);
       //CALCULATATION REPAYMENT
      amount_repayment += (double) roundedDown+ loan[index_loan].monthly_payment;;
      printf("the amount repayment is %lf\n",amount_repayment);
      value_loan += (double)roundedDown;
      printf("the remain loan si   %f\n",value_loan);
      time += 1;
      printf("the time to estinguish the loan is  %lf\n",time);
      // STORE THE VALUES
      loan[index_loan].time_repayment = time;
    }
    index_loan+=1;
  }
}
  */ 


void recoverInput(){
  double m;
  double l;
  double r;
  double p;-
  printf("Write the amount of the loan and the proposal\n");
  scanf("%lf %lf", &m, &l);
  Loan* ln = malloc(sizeof(Loan)*l);
  for(int i =0; i< l; i++){
    printf("Write the interest rate and the monthly payment\n");
    scanf("%lf %lf", &r, &p);
    ln[i] = newLoan(m, l, r, p);
    // CALCUALTE PAYBACK
  }
  calculateTwo(ln);
  free(ln);
}



/*
bool calculationPayOff(double value, double rates,double pay ){
  
}


*/


int main(void){
  recoverInput();
 

  }

  