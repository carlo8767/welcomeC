#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Loan {
  double amount_borrowed;
  double numbers_loan;
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

bool verifyPayOff(Loan *loan) {

  for (int i = 0; i < loan[0].numbers_loan; i++) {
    if (loan[i].ableLoanPayoff == true) {
      return true;
    }
    
  }
  return false;
}

// https://en.wikipedia.org/wiki/Guard_(computer_science)

int verifyBestOutput(Loan *loan) {
  int index_best_amount_repayment = 0;
  for (int i = 1; i < loan[0].numbers_loan - 1; i++) {
    // EXCLUDE WHO HAS PAYOFF FALSE
     if(loan[index_best_amount_repayment].ableLoanPayoff == false  
        || loan[i].ableLoanPayoff ==false)  {
        continue;
     }
      // VERIFY IF THEY HAVE THE SAME AMOUNT
      // VERIFY THE TIME
      if (loan[index_best_amount_repayment].amount_repayment ==
          loan[i].amount_repayment) {
        if (loan[index_best_amount_repayment].time_repayment <
            loan[i].time_repayment) {
            index_best_amount_repayment = i;
        } 
      }
      else if (loan[index_best_amount_repayment].amount_repayment <
                 loan[i].amount_repayment) {
             index_best_amount_repayment = i;
      } 
  }
  return index_best_amount_repayment;
}

void calculateLoanAmountTime(Loan *loan) {

  for (int i = 0; i < loan[0].numbers_loan; i++ ){
    double values = loan[i].amount_borrowed;
    int time = 0;
    double add_interest = 0;
    double month_pay = loan[i].monthly_payment;
    double amount_return = 0;
    while (values > 0) {
      // DIFFERENCE VERIFICATION TO AVOID OVERCOME AT 0
        values -= month_pay;
  

      // CALCULATE INTEREST AND ADD AT VALUES
      add_interest = values * (loan[i].rates_interest / (double)100);
      // ROUND DOWN
      // REMOVE
      values += floor(add_interest);
      // VERIFY IF YOU CAN PAY OFF
      // REFORMAT INT

      if (floor(add_interest) > month_pay) {
        loan[i].ableLoanPayoff = false;
        break;
      }
      if(loan[i].rates_interest == 0 && loan[i].monthly_payment == 0 ){
        loan[i].ableLoanPayoff = false;
        break;
      }


      // CALCULATE THE  TIME
      time += 1;
      // CALCUALTE AMOUNT MONEY GIVE BACK NO KEEN INTEREST RETURN
      // amount_return += (int)add_interest+month_pay;
      if (values < month_pay) {
        amount_return += month_pay;
        month_pay = values;
      } 
      else {
        amount_return = month_pay * time;
      }
    }
    loan[i].time_repayment = time;
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

// https://cwe.mitre.org/data/definitions/457
bool recoverInput() {
  double m = 0;
  double l = 0;
  double r = 0;
  double p = 0;
  scanf("%lf %lf", &m, &l);
  Loan *ln = malloc(sizeof(Loan) * l);
  int size_object = 0;
  for (int i = 0; i < l; i++) {
    scanf("%lf %lf", &r, &p);
    if (!verifyConstraintInput(m, l, r, p)) {
        continue;
    }
    else {
      ln[i] = newLoan(m, l, r, p);
      size_object+=1;
    }
  }

  if(size_object == 0){
    printf("impossible");
    free(ln);
    return false;
  }
  

  calculateLoanAmountTime(ln);
  // VERIFY THAT AT LEAST ONE OF THE LOAN CAN BE PAIOFF;
  if (!verifyPayOff(ln)) {
    printf("impossible\n");
    free(ln);
    return false;
  }
  // BEST AMOUNT
  int index_best_output = verifyBestOutput(ln);
  double out  = ln[index_best_output].amount_repayment;
  double second = ln[index_best_output].time_repayment;
  printf("%.0f %.0f\n", out, second);
  free(ln);
  return true;
}

int main(void) { recoverInput();








}
