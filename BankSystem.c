#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct address
{
	char street_name[50];
	char street_number[5];
};
struct account
{
	long int account_number;
	char first_name [20];
	char last_name [20];
	char ID[11];
	double balance;
	struct address address1;
};

double f_round(double dval, int n)
{
    char l_fmtp[32], l_buf[64];
    char *p_str;
    sprintf (l_fmtp, "%%.%df", n);
    if (dval>=0)
            sprintf (l_buf, l_fmtp, dval);
    else
            sprintf (l_buf, l_fmtp, dval);
    return ((double)strtod(l_buf, &p_str));

}

int compare_str(const void* key, const void* element)
    {
        return strcmp((char *)key, (char *)element);
    }

int get_number_of_accounts()
{
	FILE         *input;
	input = fopen("Accounts.txt", "r");

	struct account account1;
	struct address address1;
	int counter=0;

	if( (input != (FILE*) NULL) )
	{		
    	while (EOF!=fgetc(input))
    	{
    		
    		fscanf(input, "%li", &account1.account_number);
    		fscanf(input, "%s", account1.first_name);
    		fscanf(input, "%s", account1.last_name);
    		fscanf(input, "%s", account1.ID);
    		fscanf(input, "%s", address1.street_name);
    		fscanf(input, "%s", address1.street_number);
    		fscanf(input, "%lf", &account1.balance);
    		counter++;
    	}
    }

    fclose(input);

	return counter;
}
int check_if_excists(const void* key)
{
	FILE         *input;
	input = fopen("Accounts.txt", "r");

	struct account account1;
	struct address address1;
	int counter=0;

	if( (input != (FILE*) NULL) )
	{		
    	while (EOF!=fgetc(input))
    	{
    		
    		fscanf(input, "%li", &account1.account_number);
    		fscanf(input, "%s", account1.first_name);
    		fscanf(input, "%s", account1.last_name);
    		fscanf(input, "%s", account1.ID);
    		fscanf(input, "%s", address1.street_name);
    		fscanf(input, "%s", address1.street_number);
    		fscanf(input, "%lf", &account1.balance);
    		if((long int*)account1.account_number == key ||  (long int*)atol(account1.ID) == key)
    		{
    			counter++;
    			break;
    		}
    	}
    }

    fclose(input);

	return counter;
}

void display_account_data_from_number(const void* key)
{
	FILE         *input;
	input = fopen("Accounts.txt", "r");

	struct account account1;
	struct address address1;
	int counter=0;

	if( (input != (FILE*) NULL) )
	{
		printf("Account Number\tName\t\tUser ID\t\tAddress\t\tBalance\n");		
    	while (EOF!=fgetc(input))
    	{
    		
    		fscanf(input, "%li", &account1.account_number);
    		fscanf(input, "%s", account1.first_name);
    		fscanf(input, "%s", account1.last_name);
    		fscanf(input, "%s", account1.ID);
    		fscanf(input, "%s", address1.street_name);
    		fscanf(input, "%s", address1.street_number);
    		fscanf(input, "%lf", &account1.balance);
    		if((long int*)account1.account_number == key ||  (long int*)atol(account1.ID) == key)
    		{
    			printf("%li\t\t%s %s\t%s\t%s %s\t%.2lf\n", account1.account_number, account1.first_name, account1.last_name, account1.ID, address1.street_name, address1.street_number, account1.balance);
    			counter++;
    			continue;
    		}

    	}
    }

if(counter == 0)
	printf("No records found, check Your spelling.\n");

    fclose(input);
}
void display_account_data_from_string(const void* key)
{
	FILE         *input;
	input = fopen("Accounts.txt", "r");

	struct account account1;
	struct address address1;
	int counter=0;

	if( (input != (FILE*) NULL) )
	{
		printf("Account Number\tName\t\tUser ID\t\tAddress\t\tBalance\n");
    	while (EOF!=fgetc(input))
    	{
    		
    		fscanf(input, "%li", &account1.account_number);
    		fscanf(input, "%s", account1.first_name);
    		fscanf(input, "%s", account1.last_name);
    		fscanf(input, "%s", account1.ID);
    		fscanf(input, "%s", address1.street_name);
    		fscanf(input, "%s", address1.street_number);
    		fscanf(input, "%lf", &account1.balance);
    		if(compare_str(key,account1.first_name)== 0 || compare_str(key,account1.last_name)== 0|| compare_str(key,address1.street_name)== 0)
    		{
    			printf("%li\t\t%s %s\t%s\t%s %s\t%.2lf\n", account1.account_number, account1.first_name, account1.last_name, account1.ID, address1.street_name, address1.street_number, account1.balance);
    			counter++;
    			continue;
    		}
    	}
    }

if(counter == 0)
	printf("No records found, check Your spelling.\n");

    fclose(input);
}

void display_all_accounts()
{

	FILE         *input;
	input = fopen("Accounts.txt", "r");

	struct account account1;
	struct address address1;
	int counter=0;

	if( (input != (FILE*) NULL) )
	{
		printf("Account Number\tName\t\tUser ID\t\tAddress\t\tBalance\n");
    	while (EOF!=fgetc(input))
    	{
    		
    		fscanf(input, "%li", &account1.account_number);
    		fscanf(input, "%s", account1.first_name);
    		fscanf(input, "%s", account1.last_name);
    		fscanf(input, "%s", account1.ID);
    		fscanf(input, "%s", address1.street_name);
    		fscanf(input, "%s", address1.street_number);
    		fscanf(input, "%lf", &account1.balance);
    		counter++;
    		printf("%li\t\t%s %s\t%s\t%s %s\t%.2lf\n", account1.account_number, account1.first_name, account1.last_name, account1.ID, address1.street_name, address1.street_number, account1.balance);
		//printf("%d\n",counter);

    	}
    }

if(counter == 0)
	printf("No records found, check Your spelling.\n");

    fclose(input);
}

void overwrite()
{
	FILE         *input;
	FILE *buffor;
	input = fopen("Accounts.txt", "w+");
	buffor = fopen("Buffor.txt", "rw");

	struct account account1;
	struct address address1;

	if( (buffor != (FILE*) NULL) )
	{
		while (EOF!=fgetc(buffor))
    	{
    		    fprintf(input, "\n ");
			fscanf(buffor, "%li", &account1.account_number);
    			fscanf(buffor, "%s", account1.first_name);
    			fscanf(buffor, "%s", account1.last_name);
    			fscanf(buffor, "%s", account1.ID);
    			fscanf(buffor, "%s", address1.street_name);
    			fscanf(buffor, "%s", address1.street_number);
    			fscanf(buffor, "%lf", &account1.balance);
    			fprintf(input, " %li ", account1.account_number);
   				fprintf(input, "%s ", account1.first_name);
    			fprintf(input, "%s ", account1.last_name);
    			fprintf(input, "%s ", account1.ID);
    			fprintf(input, "%s ", address1.street_name);
    			fprintf(input, "%s ", address1.street_number);
    			fprintf(input, "%.2lf", account1.balance);
    	}
    }


    fclose(input);
    fclose(buffor);
}

void manage_money(const void* key, double amount)
{
	FILE         *input;
	FILE *buffor;
	input = fopen("Accounts.txt", "rw");
	buffor = fopen("Buffor.txt", "w+");

	struct account account1;
	struct address address1;

	if( (input != (FILE*) NULL) )
	{

		while (EOF!=fgetc(input))
    		{
    			fprintf(buffor, "\n ");
    			fscanf(input, "%li", &account1.account_number);
    			fscanf(input, "%s", account1.first_name);
    			fscanf(input, "%s", account1.last_name);
    			fscanf(input, "%s", account1.ID);
    			fscanf(input, "%s", address1.street_name);
    			fscanf(input, "%s", address1.street_number);
    			fscanf(input, "%lf", &account1.balance);
    			fprintf(buffor, "%li ", account1.account_number);
    			fprintf(buffor, "%s ", account1.first_name);
    			fprintf(buffor, "%s ", account1.last_name);
    			fprintf(buffor, "%s ", account1.ID);
    			fprintf(buffor, "%s ", address1.street_name);
    			fprintf(buffor, "%s ", address1.street_number);
    			if((int*)account1.account_number == key ||  (int*)account1.ID == key)
    			{

    				account1.balance+=amount;
    				if(account1.balance < 0)
    				{
    					account1.balance-=amount;
    					fprintf(buffor, "%.3lf\n", account1.balance);
    					printf("Withdrawal not possible, balance too small.");
    				}
    				else
    				{		
    					fprintf(buffor, "%.3lf\n", account1.balance);
    					fprintf(stdout, "Account nr. %li new balance: %.2lf\n",account1.account_number, account1.balance);
    				}
    			}
    			else
    			{
    				fprintf(buffor, "%.3lf", account1.balance);
    			}
    		}
    }

    fclose(input);
    fclose(buffor);
}

void deposit()
{

	long int key;
	char deposit[20];
	double deposit_double;

		printf("Enter account number to make deposit: ");
		scanf("%li", &key);
		if(check_if_excists((long int*)key))
		{
			printf("Enter amount of money to deposit: ");
			scanf("%s", deposit);
			while(atof(deposit)==0)
			{
				printf("Invalid amount, try again.");
				scanf("%s", deposit);
			}
			deposit_double=atof(deposit);
			manage_money((long int*)key,deposit_double);
			overwrite();
		}
		else printf("No account has number %li\n", key);

    
}

void withdraw()
{
	long int key;
	char withdraw[20];
	double withdraw_double;


		printf("Enter account number to make withdraw: ");
		scanf("%li", &key);
		if(check_if_excists((long int*)key))
		{
			printf("Enter amount of money to withdraw: ");
			scanf("%s", withdraw);
			while(atof(withdraw)==0)
			{
				printf("Invalid amount, try again.");
				scanf("%s", withdraw);
			}
			withdraw_double=0-atof(withdraw);
			manage_money((long int*)key,withdraw_double);
    			overwrite();
		}
		else printf("No account has number %li\n", key);


}

void transfer()
{

	long int key;
	long int key2;
	char value[20];
	double value_double;

		printf("Enter account number from which to make transfer: ");
		scanf("%li", &key);
		printf("Enter account number to which to make transfer: ");		
		scanf("%li", &key2);
		if(check_if_excists((long int*)key))
		{
			if(check_if_excists((long int*)key2))
			{
			printf("Enter amount of money to transfer: ");
			scanf("%s", value);
			while(atof(value)==0)
			{
				printf("Invalid amount, try again.");
				scanf("%s", value);
			}
			value_double=atof(value);
			value_double=0-value_double;
			//printf("Amount: %f",value_float);
			manage_money((long int*)key, value_double);
			overwrite();
			value_double=0-value_double;
			//printf("Amount: %f",value_float);
			manage_money((long int*)key2,value_double);
			overwrite();
			}
			else printf("No account has number %li\n", key2);
		}
		else printf("No account has number %li\n", key);


}

void user_add()
{

	FILE         *input;
	input = fopen("Accounts.txt", "a+");

	struct account account1;
	struct address address1;
	char balance_char [20];
	int i;
	int number_of_accounts=get_number_of_accounts();
	if( (input != (FILE*) NULL) )
	{
		number_of_accounts++;
		fprintf(input, "\n %d", number_of_accounts);
    	printf("Account nr. %d", number_of_accounts);
    	printf("\nName:");
    	scanf("%s", account1.first_name);
    	while(strlen(account1.first_name)>20)
    	{
    		printf("Name too long, max 20 characters.");
    		scanf("%s", account1.first_name);
    	}
    	fprintf(input, " %s", account1.first_name);
    	printf("\nSurename:");
    	scanf("%s", account1.last_name);
    	while(strlen(account1.last_name)>20)
    	{
    		printf("Surename too long, max 20 characters.");
    		scanf("%s", account1.last_name);
    	}
    	fprintf(input, " %s", account1.last_name);
    	printf("\nID:");
    	scanf("%s", account1.ID);
    	while(strlen(account1.ID)<11)
    	{
		
    		printf("Invalid ID, it should be an 11 digit number.\n");
    		scanf("%s", account1.ID);
    	}
	for(i=0;i<11;)
	{
		if(isdigit(account1.ID[i]))
		{
			//printf("Digit %d\n",account1.ID[i]);
			i++;
			continue;
		}
		else 
		{
			printf("Invalid ID, it should be an 11 digit number.\n");
    			scanf("%s", account1.ID);
		}
	}
    	/*while(atol(account1.ID) < 10000000000 || atol(account1.ID)>99999999999)
    	{
    		printf("Invalid ID, it should be an 11 digit number. %li\n", atol(account1.ID));
    		scanf("%s", account1.ID);
    	}*/
    	fprintf(input, " %s", account1.ID);
    	printf("\nStreet name:");
    	scanf("%s", address1.street_name);
    	while(strlen(address1.street_name)>20)
    	{
    		printf("Street name too long, max 20 characters.\n");
    		scanf("%s", address1.street_name);
    	}
    	fprintf(input, " %s", address1.street_name);
    	printf("\nStreet number:");
    	scanf("%s", address1.street_number);
    	while(strlen(address1.street_number)>5)
    	{
    		printf("Street number too big, max 5 digits.\n");
    		scanf("%s", address1.street_number);
    	}
    	while(atoi(address1.street_number) < 1 || atoi(address1.street_number) > 99999)
    	{
    		printf("Invalid street number, max 5 digits.\n");
    		scanf("%s", address1.street_number);
    	}
    	fprintf(input, " %s", address1.street_number);
    	printf("\nBalance:");
    	scanf("%s", balance_char);
    	while(atof(balance_char)==0)
    	{
    		printf("Invalid balance state.\n");
    		scanf("%s", balance_char);
    	}
    	account1.balance=atof(balance_char);
    	fprintf(input, " %.2lf", account1.balance);
    }

    fclose(input);
}


int main(int argc, char const *argv[])
{

	int operator=10;
	int buffor;
	long int number_key;
	char char_key [20];
	while(operator!=0)
	{
		operator=10;
		printf("\n");
		printf("(1) -> display all accounts\n");
		printf("(2) -> find account by number or ID\n");
		printf("(3) -> find account by name\n");
		printf("(4) -> deposit\n");
		printf("(5) -> withdraw\n");
		printf("(6) -> transfer\n");
		printf("(7) -> add new account\n");
		printf("(0) -> exit\n");
		scanf("%d", &operator);
		printf("Option: %d.\n",operator);

		switch(operator)
		{
			case 1: display_all_accounts(); break;
			case 2:  printf("Enter account number od user ID, and confirm with enter.\n");
				scanf("%li", &number_key);
				//number_key=94090702054;
				display_account_data_from_number((long int*)number_key);
				break;
			case 3: printf("Enter user's first, last or street name, and confirm with enter.\n");
				scanf("%s",char_key);
				display_account_data_from_string((char*)char_key);
				break;
			case 4: 
				deposit();
				break;
			case 5:
				withdraw();
				break;
			case 6:
				transfer();
				break;
			case 7:
				user_add();
				break;
			case 0: break;
			default: printf("Option not found, try again\n");
			
		}


	}
	
	return 0;
}
