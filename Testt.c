#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Node
{
	// structure Declaration
	long int Customer_Id;
	char Customer_Name[100];
	char Mobile_No[100];
	long int Amount;
	long int Account_Id;
	struct Node *Next;
};

struct Node *Head       	= NULL;                                                  // 4 Node Allocate
struct Node *Current    	= NULL;
struct Node *NewNode    	= NULL;
struct Node *Tail      		= NULL;
struct Node *Tmp        	= NULL;
struct Node *Search_Tmp        	= NULL;
struct Node *Search_Tmp2       	= NULL;
struct Node *Update_Tmp       	= NULL;
struct Node *Credit_Tmp 	= NULL;
struct Node *Debit_Tmp	 	= NULL;
struct Node *Fund_Tmp		= NULL;
struct Node *Recive_Tmp 	= NULL;
struct Node *Quit_Tmp	 	= NULL;


int main ()
{
	long int Account_Id = 1;
	while(1)
	{
		int Search_Account_No, Search_Menu, Search_Customer;
		int Update_Menu, Update_Account;
		long int Credit_Amount, Credit_Account , Credit_Cus ;
		long int Debit_Amount, Debit_Account , Debit_Cus;
		long int Fund_Amount, Fund_Recive, Fund_Cus, Fund_Account;
		int Check = 0;
		int ValCheck;
		FILE *F1;
		printf("\n ****** ABC BANK ***** \n\n");
		printf("1. Add Account ( Single )\n2. Add Account ( Bulk upload ) \n3. View Accounts \n4. Search Account \n5. Update Details \n6. Credit \n7. Debit\n8. Fun Transfer \n9. Quit\n\n");

		printf("Enter the choice : ");
		scanf("%d", &ValCheck);
		switch(ValCheck)
		{
			case 1:
				printf("\n Add Account ( Single ) \n");
				NewNode = malloc(sizeof(struct Node));
				//	printf("Enter the Account ID    : ");
				//	scanf("%ld", &NewNode->Account_Id);
				printf("Enter the Customer ID   : ");
				scanf("%ld", &NewNode->Customer_Id);
				getchar();
				printf("Enter the Customer_Name : ");
				scanf("%[^\n]", NewNode->Customer_Name);
				printf("Enter the Mobile No     : ");
				scanf("%s", NewNode->Mobile_No);
				printf("Enter the Amount        : ");
				scanf("%ld", &NewNode->Amount);
				NewNode->Account_Id = Account_Id;

				NewNode->Next = NULL;
				if(Head == NULL)
				{
					Head = NewNode;
					Current = Head;
				}
				else
				{
					Current->Next = NewNode;
					Current = NewNode;
				}
				Account_Id++;
				break;
			case 2:
				F1 = fopen("Bulk_Report.txt", "r");
				printf("\n Add Account ( Bulk upload ) \n");
				NewNode = malloc(sizeof(struct Node));
				while ( fscanf(F1, "%ld%s%s%ld\n", &NewNode->Customer_Id, NewNode->Customer_Name, NewNode->Mobile_No, &NewNode->Amount ) != EOF )
				{
					NewNode->Account_Id = Account_Id;
					if(Head == NULL)
					{
						Head = NewNode;
						Current = Head;
						Account_Id++;
					}
					else
					{
						Current->Next = NewNode;
						Current = NewNode;

						Account_Id++;
					}
					NewNode = malloc(sizeof(struct Node));
					NewNode->Next = NULL;
				}
				fclose(F1);
				break;

			case 3:
				printf("Account_Id\tCustomer_ID\tCustomer_Name\tMobile_No\tAmount \n");
				Tmp = Head;
				while(Tmp != NULL)
				{
					printf("%12ld\t%-12ld\t%-12s\t%-12s\t%-12ld\n", Tmp->Account_Id, Tmp->Customer_Id, Tmp->Customer_Name, Tmp->Mobile_No, Tmp->Amount);
					Tmp = Tmp->Next;
				}
				break;

			case 4:
				Search_Tmp = Head;
				printf("\n Search Account \n");
				printf("1. Search Account No \n2. Search Customer ID \n");
				printf("Enter the choice : ");
				scanf("%d", &Search_Menu);
				switch(Search_Menu)
				{
					case 1:
						printf("Enter the Account No : ");
						scanf("%d", &Search_Account_No);
						printf("Account_Id\tCustomer_ID\tCustomer_Name\tMobile_No\tAmount \n");
						while(Search_Tmp != NULL)
						{
							if( Search_Account_No == Search_Tmp->Account_Id )
							{
								printf("%-12ld\t%-12ld\t%-12s\t%-12s\t%-12ld\n", Search_Tmp->Account_Id, Search_Tmp->Customer_Id, Search_Tmp->Customer_Name, Search_Tmp->Mobile_No, Search_Tmp->Amount);
							}
							else
							{
								Check++;
							}
							Search_Tmp = Search_Tmp->Next;
						}
						if(Check <= 1)
						{
							printf("\n !! Not Found Account No !!\n");
						}
						break;
					case 2:
						Search_Tmp2 = Head;
						Check = 0;
						printf("Enter the Customer_Id : ");
						scanf("%d", &Search_Customer);
						printf("Account_Id\tCustomer_ID\tCustomer_Name\tMobile_No\tAmount \n");

						while(Search_Tmp2 != NULL)
						{
							if( Search_Customer == Search_Tmp2->Customer_Id )
							{
								printf("%ld\t%-12ld\t%-12s\t%-12s\t%-12ld\n", Search_Tmp2->Account_Id, Search_Tmp2->Customer_Id, Search_Tmp2->Customer_Name, Search_Tmp2->Mobile_No, Search_Tmp2->Amount);
							}
							else
							{
								Check++;
							}
							Search_Tmp2 = Search_Tmp2->Next;
						}
						if(Check <= 1)
						{
							printf("\n !! Not Found Account No !!\n");
						}
						break;
				}

			case 5:
				Update_Tmp = Head;
				printf("Enter the Account No : ");
				scanf("%d", &Update_Account);
				while(Update_Tmp != NULL)
				{
					if( Update_Account == Update_Tmp->Account_Id)
					{
						printf("1. Update Customer Name \n2. Update Mobile No \n");
						printf("Enter the choice : ");
						scanf("%d", &Update_Menu);
						switch(Update_Menu)
						{
							case 1:
								printf("Enter the New Customer Name : ");
								getchar();
								scanf("%[^\n]", Update_Tmp->Customer_Name);
								printf("\n *** Updated New Customer Name => %s *** \n", Update_Tmp->Customer_Name);
								break;
							case 2:
								printf("Enter the New Mobile No : ");
								getchar();
								scanf("%[^\n]", Update_Tmp->Mobile_No);
								printf("\n *** Updated New Customer Name => %s *** \n", Update_Tmp->Mobile_No);
								break;
							default:
								printf("\n!! Invalid Option !!\n");
								break;
						}
					}
					else
					{
						Check++;
					}
					Update_Tmp = Update_Tmp->Next;
				}
				break;

			case 6:
				Credit_Tmp = Head;
				printf("Enter the Account No : ");
				scanf("%ld", &Credit_Account);
				while(Credit_Tmp != NULL)
				{
					if( Credit_Account == Credit_Tmp->Account_Id)
					{
						printf("Enter the Customer ID : ");
						scanf("%ld", &Credit_Cus);
						if(Credit_Cus == Credit_Tmp->Customer_Id)
						{
							printf("Enter the Amount : ");
							scanf("%ld", &Credit_Amount);
							Credit_Tmp->Amount = Credit_Amount + Credit_Tmp->Amount;
						}
						else
						{
							printf("\n!! Invalid Customer ID !! \n");
						}

					}					                                       
				       	Credit_Tmp = Credit_Tmp->Next;
				}
				break;
			case 7:
                                Debit_Tmp = Head;
                                printf("Enter the Account No : ");
                                scanf("%ld", &Debit_Account);
                                while(Debit_Tmp != NULL)
                                {
                                        if( Debit_Account == Debit_Tmp->Account_Id)
                                        {
                                                printf("Enter the Customer ID : ");
                                                scanf("%ld", &Debit_Cus);
                                                if(Debit_Cus == Debit_Tmp->Customer_Id)
                                                {
                                                        printf("Enter the Amount : ");
                                                        scanf("%ld", &Debit_Amount );
                                                        Debit_Tmp->Amount -= Debit_Amount;
							printf("Amount Debit => %ld", Debit_Tmp->Amount);
                                                }
                                                else
                                                {
                                                        printf("\n!! Invalid Customer ID !! \n");
                                                }

                                        }
                                        Debit_Tmp = Debit_Tmp->Next;
				}
				break;
			case 8:
				Fund_Tmp = Head;
				Recive_Tmp = Head;
				printf("Enter the Account No : ");
				scanf("%ld", &Fund_Account);
				while(Fund_Tmp != NULL)
				{
					if( Fund_Account == Fund_Tmp->Account_Id)
					{
						printf("Enter the Send Customer ID : ");
						scanf("%ld", &Fund_Cus);
						if(Fund_Cus == Fund_Tmp->Customer_Id)
						{
							printf("Enter the Amount : ");
							scanf("%ld", &Fund_Amount );
							Fund_Tmp->Amount -= Fund_Amount;
						}
						else
						{
							printf("\n!! Invalid Customer ID !! \n");
						}
					}

					Fund_Tmp = Fund_Tmp->Next;
				}
				printf("Enter the Recive Account No : ");
				scanf("%ld", &Fund_Recive);
				while(Recive_Tmp != NULL)
				{
					if(Fund_Recive == Recive_Tmp->Account_Id)
					{
						Recive_Tmp->Amount += Fund_Amount;
						printf("\n*** Fund Transfer Succefully ***\n");
					}
					Recive_Tmp = Recive_Tmp->Next;
				}
				break;

			case 9:
				Quit_Tmp = Head;
				F1 = fopen("Customer_Details.txt", "a+");
				while(Quit_Tmp != NULL)
				{
					fprintf( F1, "%12ld\t%-12ld\t%-12s\t%-12s\t%-12ld\n", Quit_Tmp->Account_Id, Quit_Tmp->Customer_Id, Quit_Tmp->Customer_Name, Quit_Tmp->Mobile_No, Quit_Tmp->Amount);
					Quit_Tmp = Quit_Tmp->Next;
				}
				fclose(F1);
				printf("Qiut");
				exit(0);
		}
	}
}
