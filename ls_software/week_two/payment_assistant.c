#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



int main (){

    int a = 3;
    double b = 1.5;
    b = a * b;
    const int twenty_banknote = 20;
    const int ten_banknote = 10;
    const int five_banknote = 5;
    const int two_coin = 2;
    const int one_coin = 1;
    printf("> Enter the amount\n");
    int amount;
    scanf("%d", &amount);
        int numbers_banknote_twenty = amount/twenty_banknote;
        printf(">> €:%d: %d\n",twenty_banknote, numbers_banknote_twenty );
        amount -= twenty_banknote * numbers_banknote_twenty;
        int numbers_banknote_ten = amount/ten_banknote;
        printf(">> €:%d: %d\n",ten_banknote, numbers_banknote_ten );
        amount -= ten_banknote *numbers_banknote_ten;
        int numbers_banknote_five = amount/five_banknote;
        printf(">> €: %d  %d\n",five_banknote, numbers_banknote_five );
        amount -= five_banknote * numbers_banknote_five;
        int numbers_coins_two = amount/two_coin;
        printf(">> €: %d: %d\n",two_coin, numbers_coins_two );
        amount -= two_coin * numbers_coins_two;
        int numbers_one_coins = amount/one_coin;
        printf(">> €: %d: %d\n",one_coin, numbers_one_coins );
        amount -= one_coin * numbers_one_coins;
        // YOU CAN DEFINE THE WIDTH
        // FOR LOOP TO ENTER SPACE
   
}