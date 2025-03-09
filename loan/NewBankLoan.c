#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Loan {
  double amount_borrowed;
  int numbers_loan;
  double rates_interest;
  double monthly_payment;
  double amount_repayment;
  double time_repayment;
  bool ableLoanPayoff;
} Loan;

Loan newLoan(double m, double l, double r, double p) {
  Loan loan = {m, l, r, p, 0, 0, true};
  return loan;
}

// https://en.wikipedia.org/wiki/Guard_(computer_science)

int verifyBestOutput(Loan *loan) {
  int index_best_amount_repayment = 0;
  for (int i = 1; i < loan[0].numbers_loan; i++) {
        // VERIFY IF THEY HAVE THE SAME AMOUNT
        // VERIFY THE TIME
        if (loan[index_best_amount_repayment].amount_repayment ==
          loan[i].amount_repayment) {
            if (loan[index_best_amount_repayment].time_repayment >
                loan[i].time_repayment) {
                    index_best_amount_repayment = i;
            }
            
        }
        else if (loan[i].amount_repayment <
                loan[index_best_amount_repayment].amount_repayment) {
            index_best_amount_repayment = i;
       } 
    }

  return index_best_amount_repayment;
}

// REFACTOR
void calculateLoanAmountTime(Loan *loan) {
    
    for (int i = 0; i < loan[0].numbers_loan; i++ ){
        double values = loan[i].amount_borrowed;
        double month_pay = loan[i].monthly_payment;
        double rates = loan[i].rates_interest;
        double amount_return = 0;
        double add_interest;
        int n = values;
        int calculationTime = 0;
        for(n; n > 0;){
            // 1. PAY
            // ADJUST CALCULATION FOR THE ENDE
            values -= month_pay;
            if(values <0){
                month_pay = month_pay+ values;
            }
            add_interest = values * (rates / (double)100);
            add_interest = (int) add_interest;
            values+= add_interest;
            amount_return += month_pay;
            calculationTime +=1;
            n = values;
        }
     loan[i].time_repayment = calculationTime;
     loan[i].amount_repayment = amount_return;
    }

}
  
// https://cwe.mitre.org/data/definitions/394
bool verifyConstraintInput(double m, double l, double r, double p) {
  bool value_return = true;
  if (m <  1  || m > 1000000) {
    value_return =  false;
  } else if ( l < 1 || l > 20) {
    value_return = false;
  } else if ( r < 0 || r >  1000) {
    value_return = false;
  } else if ( p < 0 || p >  1000000) {
    value_return = false;
  } 
  return value_return;
}

bool canRepay( double amountBorrow, double interest, double monthRepayment ){
    bool repay = true;
    double amountInterest = 0;
    double verify_amount = amountBorrow;
    verify_amount -= monthRepayment;
    
    amountInterest =  verify_amount * interest/ (double)100;
     if ((int)amountInterest >= monthRepayment) {
       repay = false;
     }
     else if (amountInterest == monthRepayment){
        repay = false;
     }
     else if(amountInterest == 0 && monthRepayment == 0){
        repay = false;
     }
     return repay;
 }

// https://cwe.mitre.org/data/definitions/457
bool recoverInput() {
  double m = 0;
  double l = 0;
  double r = 0;
  double p = 0;
  scanf("%lf %lf", &m, &l);
  // ISSUE WITH THE OBJECT CREATION
  Loan *ln = malloc(sizeof(Loan) * l);
  int index_loan = 0;
  int size_object = 0;
  for (int i = 0; i < l; i++) {
    scanf("%lf %lf", &r, &p);
    if (!verifyConstraintInput(m, l, r, p)) {
        continue;
    }
    if(!canRepay(m, r, p)){
        continue;
    }

    else {
    ln[index_loan] = newLoan(m, l, r, p);
      size_object+=1;
      index_loan+=1;
      // DECREASE THE OBJECT LOAN
      ln->numbers_loan = index_loan;
    }
  }

  if(size_object == 0){
    printf("impossible");
    free(ln);
    return false;
  }
  
  calculateLoanAmountTime(ln);
  // BEST AMOUNT
  int index_best_output = verifyBestOutput(ln);
  double bestOutput  = ln[index_best_output].amount_repayment;
  double times = ln[index_best_output].time_repayment;
  printf("%.0f %.0f\n", bestOutput, times);
  free(ln);
  return true;
}

int main(void) { 

  recoverInput();





}
