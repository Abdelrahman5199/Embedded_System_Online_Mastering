#include "card.h"




DateError checkDay(int day)
{
	if (day > 30 || day < 1)
	{
		return WRONG_DAY;
	}
	return OK_DATE;
}

DateError checkMonth(int month)
{
	if (month > 12 || month < 1)
	{
		return WRONG_MONTH;
	}
	return OK_DATE;
}


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter the CardHolder's name : ");
	fgets(cardData->cardHolderName, 25, stdin);
	cardData->cardHolderName[strcspn(cardData->cardHolderName, "\n")] = 0;
	if ((strlen(cardData->cardHolderName) > NAME_MAX) || (strlen(cardData->cardHolderName) < NAME_MIN))
	{
		printf("WRONG NAME \n");
		return WRONG_NAME;
	}
	return OK_CARD;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	// Input is in format MM/YY
	printf("Enter the Card Expiry date : ");
	fgets(cardData->cardExpirationDate, 6, stdin);
	cardData->cardExpirationDate[strcspn(cardData->cardExpirationDate, "\n")] = 0;
	int month = ((cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0'));
	if (strlen(cardData->cardExpirationDate) != EXPIRE_LEN)
	{
		printf("WRONG EXP DATE\n");
		return WRONG_EXP_DATE;
	}
	else if (checkMonth(month))
	{
		printf("WRONG EXP DATE\n");
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[2] != '/')
	{
		printf("WRONG EXP DATE\n");
		return WRONG_EXP_DATE;
	}
	return OK_CARD;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Enter Primary Account Number : ");
	fgets(cardData->primaryAccountNumber, 20, stdin);
	cardData->primaryAccountNumber[strcspn(cardData->primaryAccountNumber, "\n")] = 0;
	uint8_t lengthPAN = strlen(cardData->primaryAccountNumber), i;
	if ((lengthPAN > CARD_MAX) || (lengthPAN < CARD_MIN))
	{
		printf("WRONG PAN \n");
		return WRONG_PAN;
	}

	for (i = 0; i < lengthPAN; i++)
	{
		if (!(cardData->primaryAccountNumber[i] >= '0' && cardData->primaryAccountNumber[i] <= '9'))
		{
			printf("WRONG PAN \n");
			return WRONG_PAN;
		}
	}
	return OK_CARD;

}
