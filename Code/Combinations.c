#include <stdio.h>
#include <stdlib.h>
                                                         /* Function declarations */
void Title ();                                           // The title of the program
int Read_N_Numbers (int, int);                           // Input the number "N" of numbers, where "N" belongs to the interval (6, 49]
void Print_N (int);                                      // Print the count of numbers in the interval (6, 49]
void Read_Matrix (int *, int);                           // Input the "N" numbers in the interval [1, 49] and assign them to a dynamically allocated array
int Search (int *, int, int, int, int);                  // Search in the dynamically allocated array for potential duplicate numbers
int *Read_Even_Lims ();                                  // Input the interval [0, X1]U[X1, X2]U[X2, 6] for the count of even numbers in each combination
int *Read_Sum_Lims ();                                   // Input the interval [21, Y1]U[Y1, Y2]U[Y2, 279] for the sum of the numbers in each combination
void Check_Memory (int *);                               // Check memory for dynamic allocations
void Sort (int *, int);                                  // Sort the array of numbers in ascending order
void Print_Matrix (int *, int);                          // Print the array of "N" numbers in the interval [1, 49]
void Print_Even_Lims (int *);                            // Print the interval [0, X1]U[X1, X2]U[X2, 6] for the count of even numbers in each combination
void Print_Sum_Lims (int *);                             // Print the interval [21, Y1]U[Y1, Y2]U[Y2, 279] for the sum of the numbers in each combination
int *Combos (int *, int, int *, int *);                  // Create the combinations
int Search_Evens (int *, int *, int);                    // Search for the count of even numbers in each combination
int Search_Sum (int *, int *, int);                      // Search for the sum of numbers in each combination
void Print_Combos (int *);                               // Print the combinations
void Frequency (int *, int *);                           // Calculate the frequency of appearance of each number in the printed combinations
void Print_Freq (int *);                                 // Print the frequency of appearance of each number in the printed combinations
void Print_num_Combos (int *);                           // Print the count of combinations that satisfy certain conditions
void Free_Memory (int *);                                // Free memory

int main (int argc, char **argv)                  /* main (int argc, char **argv) */
{
	system ("chcp 1253");
	
	int *Mat;                                     // Variable declarations
	int N;
	int *Lim_s, *Lim_e;
	int *c;

	N = Read_N_Numbers (6, 49);                   // Call the function "Read_N_Numbers (6, 49)"
	Mat = (int *) malloc (N * sizeof (int));      // Dynamically allocate memory to create a one-dimensional array "Mat" with the entered numbers in the interval [1, 49]
	Check_Memory (Mat);                           // Call the function "Check_Memory (Mat)"
	Read_Matrix (Mat, N);                         // Call the function "Read_Matrix (Mat, N)"
	Sort (Mat, N);                                // Call the function "Sort (Mat, N)"
	Lim_e = Read_Even_Lims ();                    // Call the function "Read_Even_Lims ()"
	Lim_s = Read_Sum_Lims ();                     // Call the function "Read_Sum_Lims ()"
	Print_Matrix (Mat, N);                        // Call the function "Print_Matrix (Mat, N)"
	Print_N (N);                                  // Call the function "Print_N (N)"
	Print_Even_Lims (Lim_e);                      // Call the function "Print_Even_Lims (Lim_e)"
	Print_Sum_Lims (Lim_s);	                      // Call the function "Print_Sum_Lims (Lim_s)"
	c = Combos (Mat, N, Lim_e, Lim_s);            // Call the function "Combos (Mat, N, Lim_e, Lim_s)"
	
	return 0;
}

void Title ()                                                                                 /* Title () */
{
	printf ("=======================================================================\n\n");
	printf ("COMBINATIONS\n\n");                                                                // The title of the program
	printf ("=======================================================================\n\n");
}

int Read_N_Numbers (int L1, int L2)                                                                 /* Read_N_Numbers (6, 49) */
{
	int x;                                                                                          // Variable declarations
	do                                                                                              /* Loop */
	{
		system ("cls");
		Title ();                                                                                   // Call the function "Title ()"
		printf ("Enter the number of numbers 'N' in the interval (6, 49] : ");
		scanf ("%d", &x);                                                                           // Input the number "N" of numbers, where "N" belongs to the interval (6, 49]
		printf ("\n-----------------------------------------------------------------------\n\n");
	} 
	while (x <= L1 || x > L2);
	
	return x;                                                                                        // Return the count "N" of numbers, where "N" belongs to the interval (6, 49]
}

void Print_N (int N)                  /* Print_N (N) */
{
	printf ("Í  : %3d\n\n", N);       // Print the count of numbers in the interval (6, 49]
}

void Read_Matrix (int *M, int N)                              /*  Read_Matrix (Mat, N) */
{
	int i;                                                    // Variable declarations
	for (i = 0; i < N; i++)                                   /* 1st Loop */
	{
		do                                                    /* 2nd Loop */
		{
			printf ("Enter a number: "); 
			scanf ("%d", M + i);                             // Input the "N" numbers in the interval [1, 49] and assign them to the dynamically allocated array "Mat"
		}
		while (Search (M, i, *(M + i), 1, 49) != -1);        // Call the function "Search (Mat, 0..N, *(Mat + 0..N), 1, 49)"
	}
}

int Search (int *M, int N, int Num, int O1, int O2)                         /* Search (Mat, 0..N, *(Mat + 0..N), 1, 49) */
{
	int j = 0;                                                              // Variable declarations
	if (N == 0)                                                             /* (~) First array position *Mat */
	{
		if (Num >= O1 && Num <= O2)                                         /* (!) The number belongs to the interval [1, 49] */
			return -1;                                                      // Return confirmation value (valid number)
		return j;                                                           // Return error value (invalid number)
	}
	else                                                                     /* (~) Array positions from *(Mat + 1) onwards */
	{
		while (Num >= O1 && Num <= O2 && j < N && *(M + j) != Num)           /* Search loop to detect potential duplicates in the array and values outside the interval [1, 49] */
			j++;                                                             // Increase the helper variable to break the constraints of entering a number in the "Mat" array
		if (j == N)                                                          /* (+) The helper variable is equal to the position in the array reached by the search */
			return -1;                                                       // Return confirmation value (valid number)
		return j;                                                            // Return error value (invalid number)
	}
}

int *Read_Even_Lims ()                                                                                                 /* Read_Even_Lims () */
{
	int *Evens;                                                                                                        // Variable declarations
	Evens = (int *) malloc (2 * sizeof (int));                                                                         // Dynamically allocate memory to create a one-dimensional array "Evens" with the two entered numbers in the interval [0, X1]U[X1, X2]U[X2, 6] for the count of even numbers in each combination
	Check_Memory (Evens);                                                                                              // Call the function "Check_Memory (Evens)"
	do                                                                                                                 /* Loop */
	{
		system ("cls");
		printf ("Enter the limits of even numbers for each combination in the interval [0, X1]U[X1, X2]U[X2, 6]\n\n");
		printf ("X1 : "); 
		scanf ("%d", Evens);                                                                                           // Input the first limit "X1" of the interval [0, X1]U[X1, X2] for the count of even numbers in each combination
		printf ("X2 : ");
		scanf ("%d", Evens + 1);                                                                                       // Input the second limit "X2" of the interval [X1, X2]U[X2, 6] for the count of even numbers in each combination
		printf ("\n");
	}
    while (*Evens < 0 || *Evens > *(Evens + 1) || *(Evens + 1) > 6);
	
	return Evens;                                                                                                      // Return the "Evens" array with limits "X1" and "X2"
}

int *Read_Sum_Lims ()                                                                                                           /* Read_Sum_Lims () */
{
	int *Sum;                                                                                                                   // Variable declarations 
	Sum = (int *) malloc (2 * sizeof (int));                                                                                    // Dynamically allocate memory for a 1D array "Sum" with the two entered numbers in the interval [21, Y1]U[Y1, Y2]U[Y2, 279] for the sum of numbers in each combination
	Check_Memory (Sum);                                                                                                         // Call the function "Check_Memory (Sum)"
	do                                                                                                                           /* Loop */
	{
		system ("cls");
		printf ("Enter the limits for the sum of the numbers in each combination in the interval [21, Y1]U[Y1, Y2]U[Y2, 279]\n\n");
		printf ("Y1 : ");
		scanf ("%d", Sum);                                                                                                      // Input the first limit "Y1" of the interval [21, Y1]U[Y1, Y2] for the sum of the numbers in each combination
		printf ("Y2 : ");
		scanf ("%d", Sum + 1);                                                                                                  // Input the second limit "Y2" of the interval [Y1, Y2]U[Y2, 279] for the sum of the numbers in each combination
		printf ("\n");
	}
	while (*Sum < 21 || *Sum > *(Sum + 1) || *(Sum + 1) > 279);
	
	return Sum;                                                                                                                 // Return the "Sum" array with limits "Y1" and "Y2"
}

void Check_Memory (int *Array)                            /* Check_Memory (Array) */
{
	if (Array == NULL)                                    /* (~) The pointer "Array" points to "NULL" */
	{
		system ("cls");
		printf ("\nMemory allocation problem\n\n");
		exit (1);                                         // Terminate the program with a return value of "1"
	}	
}

void Sort (int *M, int N)                   /* Sort (Mat, N) */
{
    int i, tmp, j;                          // Variable declarations
    for (i = 0; i < N - 1; i++)             /* 1st Loop */
        for (j = i + 1; j < N; j++)         /* 2nd Loop */
            if (*(M + i) > *(M + j))        /* (~) *M == 21 > *(M + 1) == 3 */
            {
                tmp = *(M + i);             // tmp == *M ==> tmp == 21
                *(M + i) = *(M + j);        // *M == *(M + 1) ==> *M == 3
                *(M + j) = tmp;             // *(M + 1) == tmp ==> *(M + 1) == 21
            }
}

void Print_Matrix (int *M, int N)                                  /* Print_Matrix (Mat, N) */
{
    int i;                                                         // Variable declarations
    system ("cls");
    for (i = 0; i < N; i++)                                        /* Loop */
    {
        printf ("Element [%2d] Value : %3d\n", i + 1, *(M + i));   // Print the elements of the array "Mat" with the "N" numbers in the interval [1, 49] sorted
    }
    printf ("\n");
}

void Print_Even_Lims (int *E)                            /* Print_Even_Lims (Evens) */
{ 
    int i;                                               // Variable declarations 
    for (i = 0 ; i < 2; i++)                             /* Loop */
    {
        if (i == 0)                                      /* (~) Position *Evens, where it belongs to X1 */
        {
            printf ("X1 : %3d\n", *(E + i));             // Print the first limit "X1" of the interval [0, X1]U[X1, X2] for the count of even numbers in each combination
        }
        else                                             /* (~) Position *(Evens + 1) and after */
        {
            if (i == 1)                                  /* (!) Position *(Evens + 1), where it belongs to X2 */
            {
                printf ("X2 : %3d\n\n", *(E + i));       // Print the second limit "X2" of the interval [X1, X2]U[X2, 6] for the count of even numbers in each combination
            }
        }
    }
}

void Print_Sum_Lims (int *S)                           /* Print_Sum_Lims (Sum) */
{
    int j;                                             // Variable declarations
    for (j = 0 ; j < 2; j++)                           /* Loop */
    {
        if (j == 0)                                    /* (~) Position *Sum, where it belongs to Y1 */
        {
            printf ("Y1 : %3d\n", *(S + j));           // Print the first limit "Y1" of the interval [21, Y1]U[Y1, Y2] for the sum of the numbers in each combination
        } 
        else                                           /* (~) Position *(Sum + 1) and after */
        {
            if (j == 1)                                /* (!) Position *(Sum + 1), where it belongs to Y2 */
            {
                printf ("Y2 : %3d\n\n", *(S + j));     // Print the second limit "Y2" of the interval [Y1, Y2]U[Y2, 279] for the sum of the numbers in each combination
            }
        }
    }
}

int *Combos (int *M, int N, int *E, int *S)                        /* Combos (Mat, N, Evens, Sum) */
{
    int i, j, k, l, m, n;                                          // Variable declarations
    int *Com, *Cnt, *Freq;
    int evens, sum;
    Com = (int *) malloc (6 * sizeof (int));                       // Dynamically allocate memory for a 1D array "Com" for each combination created
    Check_Memory (Com);                                            // Call the function "Check_Memory (Com)"
    Cnt = (int *) calloc (4, sizeof (int));                        // Dynamically allocate memory for a 1D array "Cnt" (initially set to "0" in each position of the array) with counters for calculating the number of combinations that meet specific conditions
    Check_Memory (Cnt);                                            // Call the function "Check_Memory (Cnt)"
    Freq = (int *) calloc (49, sizeof (int));                      // Dynamically allocate memory for a 1D array "Freq" (initially set to "0" in each position of the array) with counters for calculating the frequency of appearance of each number in the printed combinations
    Check_Memory (Freq);                                           // Call the function "Check_Memory (Freq)"
    for (i = 0; i < N - 5; i++)                                    /* 1st Loop */
        for (j = i + 1; j < N - 4; j++)                            /* 2nd Loop */
            for (k = j + 1; k < N - 3; k++)                        /* 3rd Loop */
                for (l = k + 1; l < N - 2; l++)                    /* 4th Loop */
                    for (m = l + 1; m < N - 1; m++)                /* 5th Loop */
                        for (n = m + 1; n < N; n++)                /* 6th Loop */
                        {
                            *(Com + 0) = *(M + i);                 // 1st number of the combination at position *(Com + 0) of the array "Com"
                            *(Com + 1) = *(M + j);                 // 2nd number of the combination at position *(Com + 1) of the array "Com"
                            *(Com + 2) = *(M + k);                 // 3rd number of the combination at position *(Com + 2) of the array "Com"
                            *(Com + 3) = *(M + l);                 // 4th number of the combination at position *(Com + 3) of the array "Com"
                            *(Com + 4) = *(M + m);                 // 5th number of the combination at position *(Com + 4) of the array "Com"
                            *(Com + 5) = *(M + n);                 // 6th number of the combination at position *(Com + 5) of the array "Com"
                            *Cnt = *Cnt + 1;                       // Increase the counter for calculating the number of combinations "N" for 6
                            evens = Search_Evens (Com, E, 6);      // Call the function "Search_Evens (Com, Evens, 6)"
                            sum = Search_Sum (Com, S, 6);          // Call the function "Search_Sum (Com, Sum, 6)"
                            if (evens == 1)                        /* (~) Count of evens in the combination within the limits [X1, X2] */
                            {
                                if (sum == 1)                      /* (!) Sum of the numbers in the combination within the limits [Y1, Y2] */
                                {
                                    Print_Combos (Com);           // Call the function "Print_Combos (Com)"								
                                    *(Cnt + 3) = *(Cnt + 3) + 1;   // Increase the counter for the number of combinations printed
                                    Frequency (Freq, Com);         // Call the function "Frequency (Freq, Com)"
                                }
                                else                               /* (!) Sum of the numbers in the combination outside the limits [Y1, Y2] */
                                {
                                    *(Cnt + 2) = *(Cnt + 2) + 1;   // Increase the counter for the number of combinations that met the first condition but not the second condition
                                }
                            }
                            else                                   /* (~) Count of evens in the combination outside the limits [X1, X2] */
                            {
                                *(Cnt + 1) = *(Cnt + 1) + 1;       // Increase the counter for the number that did not meet the first condition 
                            }
                        }
                        Print_num_Combos (Cnt);                    // Call the function "Print_num_Combos (N, Cnt)"
                        Print_Freq (Freq);                         // Call the function "Print_Freq (Freq)"
                        Free_Memory (M);                           // Call the function "Free_Memory (Mat)"
                        Free_Memory (E);                           // Call the function "Free_Memory (Evens)"
                        Free_Memory (S);                           // Call the function "Free_Memory (Sum)"
                        Free_Memory (Com);                         // Call the function "Free_Memory (Com)"
    return Cnt;                                                    // Return the "Cnt" array with the counters
}

int Search_Evens (int *C, int *E, int N)     /* Search_Evens (Mat, Evens, N) */
{
    int j = 0;                               // Variable declarations
    int evens = 0;
    while (j < N)                            /* Loop */
    {
        if (*(C + j) % 2 == 0)               /* (~) Even number */
        {
            evens++;                         // Increase the auxiliary variable for the count of even numbers 
            j++;                             // Increment the auxiliary variable to access the combination
        }
        else                                 /* (~) Odd number */
        {
            j++;                             // Increment the auxiliary variable to access the combination
        }
    }
    
    if (evens >= *E && evens <= *(E + 1))    /* (!) The count of even numbers belongs to the limits [X1, X2] */
        return 1;                            // Return confirmation value
    return 0;                                // Return rejection value
}

int Search_Sum (int *C, int *S, int N)       /* Search_Sum (Mat, Sum, N) */
{
    int sum = 0;                             // Variable declarations
    int j;
    for (j = 0; j < N; j++)                  /* Loop */
        sum = sum + *(C + j);                // Calculate the sum of the numbers in the combination 
     
    if (sum >= *S && sum <= *(S + 1))        /* (~) The sum of the numbers in the combination belongs to the limits [Y1, Y2] */
        return 1;                            // Return confirmation value 
    return 0;                                // Return rejection value
}

void Print_Combos (int *C)                                                                               /* Print_Combos (Com) */
{
    printf ("%2d %2d %2d %2d %2d %2d\n", *(C + 0), *(C + 1), *(C + 2), *(C + 3), *(C + 4), *(C + 5));    // Print the valid combination
}

void Frequency (int *F, int *C)                               /* Frequency (Freq, Com) */
{
    *(F + (*(C + 0) - 1)) = *(F + (*(C + 0) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 1st position of the combination
    *(F + (*(C + 1) - 1)) = *(F + (*(C + 1) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 2nd position of the combination
    *(F + (*(C + 2) - 1)) = *(F + (*(C + 2) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 3rd position of the combination
    *(F + (*(C + 3) - 1)) = *(F + (*(C + 3) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 4th position of the combination
    *(F + (*(C + 4) - 1)) = *(F + (*(C + 4) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 5th position of the combination
    *(F + (*(C + 5) - 1)) = *(F + (*(C + 5) - 1)) + 1;        // Increase the counter for the frequency of appearance of the "N" number in the 6th position of the combination
}

void Print_Freq (int *F)                                                  /* Print_Freq (Freq) */
{
    int i;                                                                // Variable declarations
    printf ("\n");
    for (i = 0; i < 49; i++)                                              /* Loop */
    {
        if (*(F + i) != 0)                                                /* (~) Print elements of the array "Freq" that do not contain the value "0" */
        {
            printf ("Frequency of [%2d] : %8d\n", i + 1, *(F + i));      // Print the frequency of appearance of each "N" number chosen for the creation of combinations
        }
    }
    Free_Memory (F);                                                      // Call the function "Free_Memory (Freq)"
}

void Print_num_Combos (int *Cnt)                                                                                            /* Print_num_Combos (Cnt) */
{
    printf ("\n");
    printf ("The count of combinations N choose 6 is                                               : %8d\n", *Cnt);          // Print the count of combinations N choose 6
    printf ("The count of combinations that did not meet the first condition                             : %8d\n", *(Cnt + 1));    // Print the count of combinations that did not meet the first condition
    printf ("The count of combinations that met the first condition but did not meet the second condition : %8d\n", *(Cnt + 2));    // Print the count of combinations that met the first condition but did not meet the second condition
    printf ("The count of printed combinations                                               : %8d\n", *(Cnt + 3));    // Print the count of printed combinations
    Free_Memory (Cnt);                                                                                                        // Call the function "Free_Memory (Cnt)"
}

void Free_Memory (int *Array)     /* Free_Memory (Array) */
{
    free (Array);                // Free memory used for creating a dynamic array
}















