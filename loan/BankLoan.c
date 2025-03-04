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

int verifyBestOutput(Loan *loan) {
  int index_best_amount_repayment = 0;
  for (int i = 0; i < loan[0].numbers_loan - 1; i++) {
    for (int o = i + 1; o < loan[0].numbers_loan; o++) {
      // VERIFY IF THEY HAVE THE SAME AMOUNT
      if (loan[index_best_amount_repayment].amount_repayment ==
          loan[o].amount_repayment) {
        if (loan[index_best_amount_repayment].time_repayment <
            loan[o].time_repayment) {
          index_best_amount_repayment = i;
        } else {
          index_best_amount_repayment = o;
        }
      } else if (loan[index_best_amount_repayment].amount_repayment <
                 loan[o].amount_repayment) {
        index_best_amount_repayment = i;
      } else {
        index_best_amount_repayment = o;
      }
    }
  }
  return index_best_amount_repayment;
}

void calculateLoanAmountTime(Loan *loan) {
  int index_loan = 0;
  while (index_loan < loan[index_loan].numbers_loan) {
    double values = loan[index_loan].amount_borrowed;
    ;
    int time = 0;
    double add_interest = 0;
    double month_pay = loan[index_loan].monthly_payment;
    double amount_return = 0;
    while (values > 0) {
      // DIFFERENCE VERIFICATION
      if (values < month_pay) {
        month_pay = values;
        values -= values;
      } else {
        values -= month_pay;
      }

      // CALCULATE INTEREST AND ADD AT VALUES
      add_interest = values * (loan[index_loan].rates_interest / (double)100);
      // ROUND DOWN
      values += floor(add_interest);
      // VERIFY IF YOU CAN PAY OFF
      if (floor(add_interest) > month_pay) {
        loan[index_loan].ableLoanPayoff = false;
        break;
      }
      // CALCULATE THE  TIME
      time += 1;
      // CALCUALTE AMOUNT MONEY GIVE BACK NO KEEN INTEREST RETURN
      // amount_return += (int)add_interest+month_pay;
      if (values < month_pay) {
        amount_return += month_pay;
      } else {
        amount_return = month_pay * time;
      }
    }
    loan[index_loan].time_repayment = time;
    loan[index_loan].amount_repayment = amount_return;
    index_loan += 1;
  }
}

bool verifyConstraintInput(double m, double l, double r, double p) {
  if ((double)1 > m || m > (double)1000000) {
    return false;
  } else if ((double)1 > l || l > (double)20) {
    return false;
  } else if ((double)0 > r || r > (double)1000) {
    return false;
  } else if ((double)0 > p || p > (double)1000000) {
  } else {
    return true;
  }
}

bool recoverInput() {
  double m;
  double l;
  double r;
  double p;
  printf("Write the amount of the loan and the proposal\n");
  scanf("%lf %lf", &m, &l);
  Loan *ln = malloc(sizeof(Loan) * l);
  for (int i = 0; i < l; i++) {
    printf("Write the interest rate and the monthly payment\n");
    scanf("%lf %lf", &r, &p);
    ln[i] = newLoan(m, l, r, p);
  }
  if (!verifyConstraintInput(m, l, r, p)) {
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
  printf("%lf %lf\n", ln[index_best_output].amount_repayment,
         ln[index_best_output].time_repayment);
  free(ln);
  return true;
}

int main(void) { recoverInput(); }
