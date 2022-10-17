#include "app.h"

void appStart(void)
{
	/* Decleration Data */

	ST_transaction_t transactionData;
	ST_cardData_t* cardData = &transactionData.cardHolderData;
	ST_terminalData_t* terminalData = &transactionData.terminalData;
	/* CARD Side */
	while (getCardHolderName(cardData));
	while (getCardExpiryDate(cardData));
	while (getCardPAN(cardData));

	/* Terminal Side */
	while (getTransactionDate(terminalData));
	if (isCardExpired(*cardData, *terminalData))
		return;
	if (isValidCardPAN(cardData))
		return;
	while (setMaxAmount(terminalData));
	while (getTransactionAmount(terminalData));
	if (isBelowMaxAmount(terminalData))
		return;

	/* Server Side */
	if (recieveTransactionData(&transactionData))
		return;


	ST_transaction_t TestGetTransaction;
	getTransaction(0, &TestGetTransaction);
	printf("\n%s\n", TestGetTransaction.cardHolderData.primaryAccountNumber);
	printf("%s\n\n", TestGetTransaction.cardHolderData.cardHolderName);

	return;
}