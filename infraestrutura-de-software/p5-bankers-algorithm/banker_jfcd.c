#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Banker's Functions */
int request_resources(int customer_num, int request[]);
void release_resources(int customer_num, int release[]);
void output_result(int customer_num, int resources[], int code);
void output_state(void);

/* Auxiliary Functions */
int count_lines(char *filename);
void read_customers(int n, int m);
void read_resources(const char *argv[], int m);
void read_commands(char **cmd, FILE *fp);
int **new_matrix(int n, int m);
void copy_array(int *dst, int *src, int len);
int is_array_leq(int *arr1, int *arr2, int n);

/* Globals */
int number_of_customers;
int number_of_resources;

int *available;   /* The available amount of each resource */
int **maximum;    /* the maximum demand of each customer */
int **allocation; /* the amount currently allocated to each customer */
int **need;       /* the remaining need of each customer */

int main(int argc, const char *argv[])
{
        number_of_customers = count_lines("customer.txt");
        number_of_resources = argc - 1;

        int n = number_of_customers;
        int m = number_of_resources;

        /* Allocating space for data structures */
        available = malloc(m * sizeof(int));
        maximum = new_matrix(n, m);
        allocation = new_matrix(n, m);
        need = new_matrix(n, m);       

        /* Reading and feeding the data */  
        read_customers(n, m);    /* customer.txt -> Maximum matrix */
        read_resources(argv, m); /* command line -> Available array */
        for (int i = 0; i < n; i++)
                copy_array(need[i], maximum[i], m); /* need starts as maximum */

        /* Will hold a command, with each index being an argument.
        Format: ACTION | Customer_num | resources (times m) | NULL. */
        char **cmd = calloc(3 + m, sizeof(char *));

        /* Clear teacher file =) */
        FILE *tmp_fp = fopen("result.txt", "w");
        fclose(tmp_fp);

        /* Banker's Execution */
        int resources[m];
        int customer_num; 
        FILE *fp_cmd = fopen("commands.txt", "r");
        while (!feof(fp_cmd)) {
                /* Fetch next command */
                read_commands(cmd, fp_cmd);

                /* If "*" -> Output state into file */
                if (!strcmp(cmd[0], "*")) {
                        output_state();
                        continue;
                }

                /* Else: Parse command resources */
                customer_num = atoi(cmd[1]);
                for (int i = 0; i < number_of_resources; i++) {
                        resources[i] = atoi(cmd[i+2]);
                }

                /* Request or release validation */
                if (!strcmp(cmd[0], "RQ")) {
                        request_resources(customer_num, resources);
                }
                else if (!strcmp(cmd[0], "RL")) {
                        release_resources(customer_num,  resources);
                }   
        }

        /* Bankers finished: Clear memory */
        fclose(fp_cmd);
        free(available);  /* The available amount of each resource */
        free(maximum);    /* the maximum demand of each customer */
        free(allocation); /* the amount currently allocated to each customer */
        free(need);       /* the remaining need of each customer */
        return 0;
}

/* Returns 0 if successful and –1 if unsuccessful */
int request_resources(int customer_num, int request[])
{

        int n = number_of_customers;
        int m = number_of_resources;
        
        /* Step 1: Maximum error check */
        if (!is_array_leq(request, need[customer_num], m)) {
                output_result(customer_num, request, -2);
                return -1;
        }

        /* Step 2: Available error check */
        if (!is_array_leq(request, available, m)) {
                output_result(customer_num, request, -3);
                return -1;
        }

        /* Step 3: Pretend request was granted to customer 
        to later check if it leaves the state unsafe or not */
        int tmp_av[m];
        int tmp_alloc[n][m];
        int tmp_need[n][m];

        /* Copy current state to temporary state */
        copy_array(tmp_av, available, m);
        for (int i = 0; i < n; i++) {
                copy_array(tmp_alloc[i], allocation[i], m);
                copy_array(tmp_need[i], need[i], m);
        }

        /* Simulate as if request was granted 
        Updating TEMPORARY AVAILABLE and ALLOCATION */
        for (int i = 0; i < m; i++) {
                tmp_av[i] -= request[i]; /* available -= request */
                tmp_alloc[customer_num][i] += request[i]; /* allocation += request */
        }

        /* Update temporary NEED */
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        tmp_need[i][j] = maximum[i][j] - tmp_alloc[i][j];
                }
        }

        /** STEP 4: Check if state is safe or not **/
        int finish[n]; /* Initialize all processes as unfinished */
        memset(finish, 0, n * sizeof(int)); 
        
        int work[m]; /* Copy available resources */
        copy_array(work, tmp_av, m); 

        /* Runs while not all proccess have finished
        or some cant be finished */
        int count = 0; 
        while (count < n) { 
                int found = 0;
                for (int i = 0; i < n; i++) { 
                        /* Find a customer which finish[i] == false
                        * and need[i] <= work (can be satisfied) */
                        if (!finish[i]) { 
                                int j; 
                                for (j = 0; j < m; j++) 
                                        if (!(tmp_need[i][j] <= work[j])) 
                                                break;
                                /* If customer found */
                                if (j == m) {
                                        /* Update work and finished */
                                        finish[i] = 1; 
                                        for (int k = 0 ; k < m ; k++) 
                                                work[k] += tmp_alloc[i][k]; 
                                        found = 1;
                                        count++; 
                                } 
                        } 
                } 
		/* If any i couldnt be found the state is unsafe */
		if (!found) { 
                        output_result(customer_num, request, -1);
                        return -1;
		} 
	}
        
        /* IS SAFE: Update the current state and output success */
        copy_array(available, tmp_av, m);
        for (int i = 0; i < n; i++) {
                copy_array(allocation[i], tmp_alloc[i], m);
                copy_array(need[i], tmp_need[i], m);
        }
        output_result(customer_num, request, 0);
        return 0; 
}


void release_resources(int customer_num, int release[])
{
        int m = number_of_resources;
        int qt;
        for (int i = 0; i < m; i++) {
                qt = release[i];
                /* Prevent releasing more than possible */
                if (qt > allocation[customer_num][i])
                        qt = allocation[customer_num][i];
                /* Release */
                allocation[customer_num][i] -= qt;
                available[i] += qt;
        }
        output_result(customer_num, release, 1);
}

/* Counts lines by the quantity of "\n" */
int count_lines(char *filename)
{
        FILE *fp = fopen(filename, "r");

        int lines = 0;
        char ch;
        while (!feof(fp)) {
                ch = fgetc(fp);
                if (ch == '\n')
                        lines++;
        }
        fclose(fp);
        return (lines+1);
}

/* customer.txt -> Maximum matrix */
void read_customers(int n, int m)
{
        FILE *fp = fopen("customer.txt", "r");
        int num;
        for (int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        fscanf(fp,"%d,",&num);
                        maximum[i][j] = num;
                }
        }
        fclose(fp);
}

/* command line -> Available array */
void read_resources(const char *argv[], int m)
{
        for (int i = 0; i < m; i++)
                available[i] = atoi(argv[i+1]);
}

/* Reads one line at a time and parses the input into the CMD array */
void read_commands(char **cmd, FILE *fp)
{
        char buffer[264]; /* Arbitrary maximum size for a command */

        /* Gets input */
        char ch;
        for (int i = 0; !feof(fp); i++) {
                buffer[i] = fgetc(fp);
                if (buffer[i] == '\n' || buffer[i] == EOF) {
                        buffer[i] = '\0';
                        break;
                }
        }
        /* Parses input */
        int size;
        int pos = 0;
	char *pc = strtok(buffer, " ");
	while (pc != NULL) {
		/* Size count */
		size = 0;
		for (int i = 0; ; i++) {
			size++;
			if (pc[i] == '\0')
				break;
		}
		cmd[pos] = malloc(size * sizeof(char));
		strcpy(cmd[pos], pc);
		pc = strtok(NULL, " ");
		pos++;
	}
	cmd[pos] = NULL;
}

/* Allocates a matrix in heap. Values inialized as 0 */
int **new_matrix(int n, int m)
{
	int** mat = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		mat[i] = calloc(m, sizeof(int));
	return mat;
}

/* Copies every element from src into dst */
void copy_array(int *dst, int *src, int len)
{
        for (int i = 0; i < len; i++)
                dst[i] = src[i];
}

/* Output the state of the resources into the result file */
void output_state(void)
{
        FILE *fp_out = fopen("result.txt", "a");
        int n = number_of_customers;
        int m = number_of_resources;

        fputs("MAXIMUM | ALLOCATION | NEED\n", fp_out);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        if (j == m-1)
                                fprintf(fp_out, "%-3d | ",maximum[i][j]);
                        else 
                                fprintf(fp_out, "%d ", maximum[i][j]);
                }
                for (int j = 0; j < m; j++) {
                        if (j == m-1)
                                fprintf(fp_out, "%-6d | ",allocation[i][j]);
                        else 
                                fprintf(fp_out, "%d ", allocation[i][j]);
                }
                for (int j = 0; j < m; j++)
                        fprintf(fp_out, "%d ", need[i][j]);
                fputs("\n", fp_out);
        }

        fputs("AVAILABLE ", fp_out);
        for (int i = 0; i < m; i++) {
                fprintf(fp_out, "%d ", available[i]);
        }
        fputs("\n", fp_out);

        fclose(fp_out);
}

/* Writes out operation result based on the given success code
*  -3 = ERR: Not enough resources in AVAILABLE
*  -2 = ERR: Asking more stated in MAXIMUM
*  -1 = ERR: State is unsafe
*   0 = SUCC: Request
*   1 = SUCC: Release */
void output_result(int cust_num, int resources[], int code)
{
        int n = number_of_customers;
        int m = number_of_resources;

        FILE *fp_out = fopen("result.txt", "a");

        /* ERROR: Not enough resources */
        if (code == -3) {
                fputs("The resources ", fp_out);
                for (int i = 0; i < m; i++) {
                        fprintf(fp_out, "%d ", available[i]);
                }
                fprintf(fp_out, 
                        "are not enough to customer %d request ", 
                        cust_num);
                for (int i = 0; i < m; i++) {
                        fprintf(fp_out, "%d ", resources[i]);
                } 
                fputs("\n", fp_out);   
        }
        /* ERROR: Asking more than promised */
        else if (code == -2) {
                fprintf(fp_out, "The customer %d request ", cust_num);
                for (int i = 0; i < number_of_resources; i++) {
                        fprintf(fp_out, "%d ", resources[i]);
                }
                fputs("was denied because exceed its maximum allocation\n",
                        fp_out); 
        }
        /* ERROR: System state is unsafe */
        else if (code == -1) {
                fprintf(fp_out, 
                        "The customer %d request ", 
                        cust_num);
                for (int i = 0; i < m; i++) {
                        fprintf(fp_out, "%d ", resources[i]);
                }
                fputs("was denied because result in an unsafe state\n",
                        fp_out);  
        }
        /* SUCCESS: Request resources */
        else if (code == 0) {
                fprintf(fp_out, 
                        "Allocate to customer %d the resources ", 
                        cust_num);
                for (int i = 0; i < m; i++) {
                        fprintf(fp_out, "%d ", resources[i]);
                }
                fputs("\n", fp_out);
        }
        /* SUCCESS: Release resources */
        else if (code == 1) {
                "Release from customer %d the resources %d %d %d";
                fprintf(fp_out, 
                        "Release from customer %d the resources ", 
                        cust_num);
                for (int i = 0; i < m; i++) {
                        fprintf(fp_out, "%d ", resources[i]);
                }
                fputs("\n", fp_out);
        }
        fclose(fp_out);
}

/* Returns 1 if arr1 is less or equal than array 2 */
int is_array_leq(int *arr1, int *arr2, int n)
{
        for (int i = 0; i < n; i++)
                if (!(arr1[i] <= arr2[i]))
                        return 0;
        return 1;
}