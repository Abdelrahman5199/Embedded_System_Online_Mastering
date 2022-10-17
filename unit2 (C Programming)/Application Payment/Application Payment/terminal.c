#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter Transaction Date : ");
	fgets(termData->transactionDate, 11, stdin);
	termData->transactionDate[strcspn(termData->transactionDate, "\n")] = 0;
	int month = ((int)termData->transactionDate[3] - '0') * 10 + ((int)termData->transactionDate[4] - '0');
	int day = ((int)termData->transactionDate[0] - '0') * 10 + ((int)termData->transactionDate[1] - '0');
	if (strlen(termData->transactionDate) != TRANSACTION_LEN)
	{
		printf("WRONG DATE \n");
		return WRONG_DATE;
	}
	else if (checkDay(day) || checkMonth(month))
	{
		printf("WRONG DATE \n");
		return WRONG_DATE;
	}
	else if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
	{
		printf("WRONG DATE \n");
		return WRONG_DATE;
	}
	return OK_TERMINAL;
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	int MonthExp = (cardData.cardExpirationDate[0] - '0') * 10 + (cardData.cardExpirationDate[1] - '0');
	int MonthNow = (termData.transactionDate[3] - '0') * 10 + (termData.transactionDate[4] - '0');
	int YearExp = (cardData.cardExpirationDate[3] - '0') * 10 + (cardData.cardExpirationDate[4] - '0');
	int YearNow = (termData.transactionDate[8] - '0') * 10 + (termData.transactionDate[9] - '0');
	if (YearExp < YearNow)
	{
		printf("EXPIRED CARD \n");
		return EXPIRED_CARD;
	}
	else
	{
		if (YearExp == YearNow)
		{
			if (MonthExp < MonthNow)
			{
				printf("EXPIRED CARD \n");
				return EXPIRED_CARD;
			}
			else
			{
				return OK_TERMINAL;
			}
		}
		else
		{
			return OK_TERMINAL;
		}
	}
}




EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Enter Transaction amount : ");
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		printf("INVALID AMOUNT\n");
		return INVALID_AMOUNT;
	}
	return OK_TERMINAL;
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
	uint8_t lengthPAN = strlen(cardData->primaryAccountNumber), i;
	/* Convert to Interger numbers */
	long long int PAN = 0;
	for (i = 0; i < lengthPAN; i++)
	{
		PAN += (long long int)(cardData->primaryAccountNumber[i] - '0') * (long long int)pow(10.0, (lengthPAN - i - 1));
	}
	/*Luhn Algorithm */
	long digitPosition = 1, sum = 0;
	while (PAN > 0)
	{
		//check even numbers and double it if odd let it
		if (digitPosition % 2 == 0)
		{
			// CHECK IF THE DOUBLE EVEN GREATER THAN 10 
			int Temp = (2 * (PAN % 10));
			if (Temp > 9)
			{
				sum += ((Temp % 10) + 1);
			}
			else
			{
				sum += (2 * (PAN % 10));
			}
			PAN /= 10;
		}
		else
		{
			sum += (PAN % 10);
			PAN /= 10;
		}
		digitPosition++;
	}
	if (sum % 10 == 0)
	{
		return OK_TERMINAL;
	}
	printf("INVALID CARD\n");
	return INVALID_CARD;
}




EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		printf("EXCEED MAX AMOUNT\n");
		return EXCEED_MAX_AMOUNT;
	}
	return OK_TERMINAL;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Enter MAX amount : ");
	scanf_s("%f", &termData->maxTransAmount);
	if (termData->maxTransAmount <= 0)
	{
		printf("INVALID MAX AMOUNT\n");
		return INVALID_MAX_AMOUNT;
	}
	return OK_TERMINAL;
}