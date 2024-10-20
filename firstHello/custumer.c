#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h> 


const double richCustomer = 1000000.00;
const char paperoniUser [50]  = "This is a paperoni user!!";
const char paperinoUser [50] = "This is a paperino user!!";


struct CustomerBank {
    char name [50];
    char lastName [50];
    double valueRevenue;
} customerBank;


bool verifyRevenue (double valueRevenueCustomer ){
    bool richUser = true;
    if(valueRevenueCustomer > richCustomer ){
        return richUser;
    }
    else{
        return richUser = false;
    }

}

void  printTypeCustomer (bool typeUser){

    switch(typeUser){
        case true:
            printf("%s\n", paperoniUser);
        break;
        case false:
            printf("%s\n", paperinoUser);
        break;
    }
}

int main (void){
     CustomerBank newCustomer = {"Donald", "Trump", 2000000.00};
    bool resultRevenue = verifyRevenue(newCustomer.valueRevenue);
    printTypeCustomer(resultRevenue);
    return 0;
}



