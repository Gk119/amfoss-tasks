//All these header files are needed to support code, or are they all there?
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

void showInput(int);

//Typos are a cause of huge pain for every coder
int main(void)
{
	int score = 0;
	int gameCount;
	printf("\n\n Enter number of rounds of Guessing Game ");
	scanf("%d", &gameCount);
	int originalScore = gameCount;

	while (gameCount > 0)
	{
		//every great statement should have a great ending, look out for them!
		char inputWord[100], tempWord[100];
		char finalOutput[100];
		int wrongTry, matchFound = 0;
		int counter = 0, position = 0, winner = 1, length, trial;
		char alphabetInput;

		system("cls");
		printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the Guessing Game!!!!!!!!!!!!!!!!!\n\n\n");
		//Formatting and labeling always go hand in hand!
		printf("\n\n Enter number of wrong attempts allowed: ");
		scanf("%d", &trial);
		printf("\nEnter any word in small letters and press ENTER");
		printf("\nEnter ==>  ");
		scanf("%s", inputWord);
		printf("\nLets start ask your friend to play!!!");
		printf("\nPress Enter");
		getchar();
		//Semantics are not to be overlooked!
		length = strlen(inputWord);
		wrongTry = trial + 1;;


		system("cls");

		printf("\n\n You will get %d chances to guess the correct word", wrongTry + length);
		printf("\n\n So help Alen and Joseph and get...set...GO..!!");

		getchar();

		printf("\nPress enter ");

		getchar();

		system("cls");

		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");

		//Conditions have to met to achieve results :D
		printf("\n\n     The word has %d alphabets \n\n", length);
		for (int i = 0; i < length; i++)
		{
			finalOutput[i] = '_';
			finalOutput[length] = '\0';
		}

		//Declare your purpose, and you shall be rewarded!
		for (int i = 0; i < length; i++)
		{
			printf(" ");
			printf("%c", finalOutput[i]);

		}
		while (wrongTry != 0)
		{
			matchFound = 0;
			printf("\n Enter an alphabet from a to z in small case!!");
			printf("\n\n\t Enter ->  ");

			fflush(stdin);

			scanf("%c", &alphabetInput);
			if (alphabetInput < 'a' || alphabetInput > 'z')
			{
				system("cls");
				printf("\n\n\t Wrong input, try again ");
				matchFound = 2;
			}
			fflush(stdin);

			if (matchFound != 2)
			{
				matchFound = 0; //
				for (counter = 0; counter < length; counter++)
				{
					if (alphabetInput == inputWord[counter])
					{
						matchFound = 1;
					}
				}

				if (matchFound == 0)
				{
					printf("\n\t :( You have %d tries left \n", --wrongTry);
					char x;
					scanf("%c", &x); //fflush(stdin) doesnt work here. Due to undefined nehaviour as per stackoverflow
					getchar();
					showInput(wrongTry % 5);
					getchar();
				}

				else
				{
					//Format the loops properly else iterate for eternity
					for (counter = 0; counter < length; counter++)
					{
						matchFound = 0;
						if (alphabetInput == inputWord[counter])
						{
							position = counter;
							matchFound = 1;
						}
						if (matchFound == 1)
						{
							for (int i = 0; i < length; i++)
							{
								if (i == position)
								{
									finalOutput[i] = alphabetInput;
								}
								else if (finalOutput[i] >= 'a' && finalOutput[i] <= 'z')
								{
									continue;
								}
								else
								{
									finalOutput[i] = '_';
								}
							}
							
							
						}
						if (matchFound == 1)
						{
							tempWord[position] = alphabetInput;
							tempWord[length] = '\0';
							winner = strcmp(tempWord, inputWord);
						}
						//Never forget your maths, else you'll be in trouble!
						if (winner == 0)
						{
							score = score + 1;
							printf("\n\n\t \t Nice You are the WINNER !!!!!");
							printf("\n\n\t The Word was %s ", inputWord);
							printf("\n\n\n\n\t\tEASY HUH???\n\n");
							getchar();
							break;
						}
					}
				}
			}


			printf("\n\n\t");
			for(int i = 0 ; i < length ; i++)	
			{
				printf(" ");
				printf("%c", finalOutput[i]);
			}

			getchar();
			if (winner == 0) break;
		}

		if (wrongTry <= 0)
		{
			printf("\n\n\t The Word was %s ", inputWord);
			printf("\n\n\t Better luck next round");

		}
		getchar();
		gameCount = gameCount - 1;
	}
	printf("\n\n\t The Game Score %d / %d", score, originalScore);
	getchar();
	return 0;
};



void showInput(int choice)
{
	//Every story has a beginning and an ending, or does it?

	switch (choice)
	{

	case 0:
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||   / %c", '\\');
		printf("\n\t||      ");
		break;
	case 1:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||     %c", '\\');
		printf("\n\t||      ");
		break;
	case 2:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 3:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 4:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO ", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 5:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||    O ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	default:
		return;
	}
}
