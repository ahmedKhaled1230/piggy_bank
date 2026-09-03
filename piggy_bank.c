#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define COIN_KINDS   5U
#define TOY_COUNT    4U
#define NAME_LEN    16U

/* the coins we know about, in piastres */
static const uint16_t COIN_VALUE[COIN_KINDS] = { 25U, 50U, 100U, 200U, 500U };

/* how many of each coin are in the bank right now */
static uint16_t coinCount[COIN_KINDS];

typedef struct {
    char     name[NAME_LEN];
    uint32_t price;        /* in piastres */
} Toy_t;

static Toy_t shop[TOY_COUNT];

static void     seedBank(void);
static void     addCoins(void);
/*
static void     takeCoins(void);
static uint32_t bankTotal(void);
static uint32_t sumCoins(const uint16_t *counts, uint8_t n);
static uint8_t  biggestPile(void);
static void     showBank(void);
static void     drawBar(uint16_t value, uint16_t full, uint8_t width);
static void     buyToy(void);
static void     bankReport(void);
*/
int main(void) {
    seedBank();
    unsigned short int choice;
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add coins\n");
        printf("2. Take coins\n");
        printf("3. Show bank\n");
        printf("4. Buy toy\n");
        printf("5. Bank report\n");
        printf("0. Exit\n");
        printf("Choice: ");
        if (scanf("%hu", &choice) != 1 || choice > 5) {
            printf("Invalid input!\n");
            while(getchar()!='\n'); // clear the input buffer
            continue;

        }
        switch (choice) {
            case 1: addCoins(); break;
            /*
            case 2: takeCoins(); break;
            case 3: showBank(); break;
            case 4: buyToy(); break;
            case 5: bankReport(); break;*/
            case 0: break;
            
            default: printf("Unknown option!\n"); break;
        }
        if (choice==0){
            break;
        }
    } 
    return 0;
}
static void seedBank(void) {
    for (uint8_t i = 0; i < COIN_KINDS; i++) {
        coinCount[i] = 2; // start with 2 coins each
    }
    strcpy(shop[0].name, "Ball");   shop[0].price = 150;
    strcpy(shop[1].name, "Car");    shop[1].price = 300;
    strcpy(shop[2].name, "Doll");   shop[2].price = 500;
    strcpy(shop[3].name, "Puzzle"); shop[3].price = 700;
}
static void addCoins(void) {
    int coin, qty;
    printf("Which coin (0-4)? ");
    if (scanf("%d", &coin) != 1 || coin < 0 || coin >= COIN_KINDS) {
        printf("Invalid coin!\n");
        return;
    }
    printf("How many? ");
    if (scanf("%d", &qty) != 1 || qty < 0) {
        printf("Invalid number!\n");
        return;
    }
    coinCount[coin] += (uint16_t)qty;
}
static void takeCoins(void) {
    int coin, qty;
    printf("Which coin (0-4)? ");
    if (scanf("%d", &coin) != 1 || coin < 0 || coin >= COIN_KINDS) {
        printf("Invalid coin!\n");
        return;
    }
    printf("How many? ");
    if (scanf("%d", &qty) != 1 || qty < 0) {
        printf("Invalid number!\n");
        return;
    }
    if (coinCount[coin] < (uint16_t)qty) {
        printf("Not enough coins!\n");
        return;
    }
    coinCount[coin] -= (uint16_t)qty;
}
