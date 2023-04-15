#pragma once

#ifndef CARD_H
#define CARD_H

#include <string.h>
#include <stdio.h>

/* Define for Max and Min Values */
#define NAME_MIN 20
#define NAME_MAX 24
#define CARD_MAX 19
#define CARD_MIN 16
#define EXPIRE_LEN 5

typedef unsigned char uint8_t;


typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

typedef enum DateError
{
	OK_DATE, WRONG_MONTH, WRONG_DAY
}DateError;

/* This function will ask for the cardholder's name and store it into card data.
Card holder name is 24 characters string max and 20 min.
If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return OK. */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);

/* This function will ask for the card expiry date and store it in card data.
Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return OK. */
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);

/* This function will ask for the card's Primary Account Number and store it in card data.
PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return OK. */
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

/* Validate Day 1 -> 30 */
DateError checkDay(int day);

/* Validate Month 1 -> 12  */
DateError checkMonth(int month);



#endif