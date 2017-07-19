#include <stdio.h>
#include <string.h>
#include <math.h>

struct Marks{
	char name[50];
	char reg_number[15];
	double STA1201;
	double STA1202;
	double STA1203;
};

typedef struct Marks Marks;

double get_double(char* prompt);
double Total(Marks sample);
double Mean(Marks sample);
double standard_deviation(Marks sample);
double coefficient(Marks sample);
void get_info(Marks* sample);
void display_info(Marks sample);
void flush();
void print_headings();

int main()
{

	Marks Bstat1;
	Marks Acturial1;

	printf("%s\n", "Filling in Bstat1 student's data");
	get_info(&Bstat1); //pass address rather than reference
	
	printf("%s\n","Acturial1 students' Informatiom" );
	get_info(&Acturial1);

	print_headings();
	display_info(Bstat1);
	display_info(Acturial1);


	return 0;

}

double Total(Marks sample)
{
	double ans = (sample.STA1201 + sample.STA1202  + sample.STA1203 );
	return ans;
}

double Mean(Marks sample)
{
	double ans = Total(sample)/3;
	return ans;
}

double standard_deviation(Marks sample)
{
	double avg  = Mean(sample);
	double variance = ( pow((avg - sample.STA1201),2) + pow((avg - sample.STA1201),2) + pow((avg - sample.STA1201),2));
	double SD = sqrt(variance);
	return SD;
}

double coefficient(Marks sample)
{
	double working  = standard_deviation(sample)/Mean(sample); //these had been swapped
	double answer = working * 100;
	return answer;
}


void get_info(Marks* sample)
{
	printf("Please enter your name: ");
	scanf("%s", (*sample).name);

	printf("Please enter the Registration number: ");
	scanf("%s", (*sample).reg_number);

	(*sample).STA1201= get_double("Please enter Marks for STA1201: ");
	(*sample).STA1202= get_double("Please enter Marks for STA1202: ");
	(*sample).STA1203= get_double("Please enter Marks for STA1203: ");

}


void display_info(Marks sample)
{
	double total = Total(sample);
	double mean = Mean(sample);
	double SD = standard_deviation(sample);
	double coefficience = coefficient(sample);

	printf("%-15s ", sample.name );
	printf("%-15s ", sample.reg_number );
	printf("%-15f ", sample.STA1201 ); //%f
	printf("%-15f ", sample.STA1202 );
	printf("%-15f ", sample.STA1203 );
	printf("%-15f ", total );
	printf("%-15f ", mean );
	printf("%-15f ", SD );
	printf("%-15f\n", coefficience);

}

//prompts for an double to be input, rejecting invalid values
double get_double(char* prompt)
{
	int a;
	double b;
	printf("%s:\t", prompt);
	retry:
	a= scanf("%lf", &b); //lf for doubles and we pass scanf the address not reference(%s is already an address)
    if (a!=1)
    {
        printf("Please Enter a Valid Value :(\t");
        flush();
        goto retry;
    }
    return b;
}

void flush()
{
	int c;
	do
	{
		c= getchar();
	}while (c!='\n' && c!=EOF);
}

void print_headings()
{
	printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Name", "Reg. No.", "STA1201", "STA1202", "STA1203", "Total", "Mean", "Std. D", "Coeff.");
}