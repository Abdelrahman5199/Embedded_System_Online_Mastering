#include "server.h"
#include "../card/card.h"
#include "../terminal/terminal.h"


/* Using this website https://www.dcode.fr/luhn-algorithm to generate Luhn Numbers */
extern ST_accountsDB_t serverDatabase[MAX_SERVER] = {
	{5000.0, "607833656635906773"},
	{4000.5, "005768153188661175"},
	{3000.2, "075982963293069095"},
	{2000.12, "611153338528212031"},
	{1000.334, "910398034808780349"},
	{1002.4, "053325461606192194"},
	{999.2, "742772749714646812"},
	{324.2, "209325396074423440"},
	{1231.4, "851079961065873585"},
	{1253.4, "442875351414250640"},
	{5123.5, "615903891876676888"},
	{6345.1, "59022961351481653"},
	{6345.6, "91119474574056192"},
	{1241.7, "89928622813608190"},
	{4761.3, "78687103102360615"},
	{125.7, "8316351323704972"},
	{214.6, "5006447651585560"},
	{1251.3, "3870771107430131"},
	{151.6, "0354025546355735"}
};


extern ST_transaction_t transactionDatabase[MAX_TRANSACTION] = { 0 };

/* cardTemp use as a buffer to transfer data */
ST_cardData_t cardTemp;
int sequenceNumber, accountOffset = 0;


/* This fanction use to search about the account
using string compare if it return 0 that mean there is same
so the function return the INDEX of the account in the database array */

int searchAccount(ST_cardData_t* cardData)
{
	for (int i = 0; i < MAX_SERVER; i++)
	{
		if (strcmp(cardData->primaryAccountNumber, serverDatabase[i].primaryAccountNumber) == 0)
		{
			return i;
		}
	}
	return -1;
}


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	if (isValidAccount(&(transData->cardHolderData)))
	{
		printf("DECLINED STOLEN CARD \n");
		transactionDatabase[sequenceNumber].transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	else if (isAmountAvailable(&(transData->terminalData)))
	{
		printf("DECLINED INSUFFECIENT FUND \n");
		transactionDatabase[sequenceNumber].transState = DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}
	else if (saveTransaction(transData))
	{
		printf("INTERNAL SERVER ERROR \n");
		transactionDatabase[sequenceNumber].transState = INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}
	else
	{
		serverDatabase[accountOffset].balance -= transData->terminalData.transAmount;
		printf("New Balance in Account : %f \n", serverDatabase[accountOffset].balance);
		transactionDatabase[sequenceNumber].transState = APPROVED;
		return APPROVED;
	}
}


EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	cardTemp = *cardData;
	accountOffset = searchAccount(cardData);
	if (accountOffset == -1)
	{
		printf("DECLINED STOLEN CARD \n");
		return DECLINED_STOLEN_CARD;
	}
	else
	{
		return OK;
	}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (serverDatabase[accountOffset].balance < termData->transAmount)
	{
		printf("LOW BALANCE \n");
		return LOW_BALANCE;
	}
	return OK;
}


EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if (sequenceNumber < 255)
	{
		transactionDatabase[sequenceNumber] = *transData;
		transactionDatabase[sequenceNumber].transactionSequenceNumber = sequenceNumber;
		transactionDatabase[sequenceNumber].transState = APPROVED;
		sequenceNumber++;
		return OK;
	}
	printf("SAVING FAILED \n");
	return SAVING_FAILED;

}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	for (uint8_t i = 0; i < sequenceNumber; i++)
	{
		if (transactionDatabase[i].transactionSequenceNumber == transactionSequenceNumber)
		{
			*transData = transactionDatabase[i];
			return OK;
		}

	}
	printf("TRANSACTION NOT FOUND \n");
	return TRANSACTION_NOT_FOUND;
}