#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Banker's Functions */
int request_resources(int customer_num, int request[]);
void release_resources(int customer_num, int release[]);
int check_safety(int av[], int *alloc[], int *nd[]);
void output_resources(void);
void output_succ_rq(int customer_num, int request[]);
void output_succ_rl(int customer_num, int release[]);
void output_err_unsafe(int customer_num, int request[]);
void output_err_max(int customer_num, int request[]);
void output_err_av(int customer_num, int request[]);

/* Auxiliary Functions */
int count_lines(char *filename);
void read_customers(char *filename, int n, int m);
void read_resources(const char *argv[], int m);
void read_commands(char **cmd, FILE *fp);
int **alloc_matrix(int n, int m);
void copy_array(int *dst, int *src, int len);
int arrcmp_leq(int arr1[], int arr2[], int n);

/* Debug Functions */
void print_array(int *array, int n);
void print_matrix(int **matrix, int n, int m);
void print_cmd(char **cmd);

/* Globals */
FILE *fp_rslt; /* Output log >> results.txt */

int number_of_customers;
int number_of_resources;

int *available;   /* The available amount of each resource */
int **maximum;    /* the maximum demand of each customer */
int **allocation; /* the amount currently allocated to each customer */
int **need;       /* the remaining need of each customer */

int main(int argc, const char *argv[])
{
        /* Initializing data structures */
        number_of_customers = count_lines("customer.txt");
        number_of_resources = argc - 1;
        
        available = malloc(number_of_resources * sizeof(int));
        maximum = alloc_matrix(number_of_customers, number_of_resources);
        allocation = alloc_matrix(number_of_customers, number_of_resources);
        need = alloc_matrix(number_of_customers, number_of_resources);        

        /* Populating data structures */  
        read_customers( 
                "customer.txt", 
                number_of_customers, 
                number_of_resources
                ); /* Maximum */
        read_resources(argv, number_of_resources); /* Available */
        for (int i = 0; i < number_of_customers; i++) { /* Need */
                for (int j = 0; j < number_of_resources; j++) {
                        /* need = maximum, because allocation starts as 0 */
                        need[i][j] = maximum[i][j];
                }
        }

        /* Will hold a command, with each index being an argument.
        Format: OPERATION | TaskNum | resources (m times) | NULL. */
        char **cmd = calloc(3 + number_of_resources, sizeof(char *));
        
        /* Requests and releases */
        int resources[number_of_resources];
        int customer_num; 

        /* Banker's Execution */
        fp_rslt = fopen("result.txt", "w");
        FILE *fp_cmd = fopen("commands.txt", "r");
        while (!feof(fp_cmd)) {
                /* Fetch next command and take action */
                read_commands(cmd, fp_cmd);
                if (!strcmp(cmd[0], "*")) {
                        output_resources();
                        continue;
                }
                /* Parse request/release command */
                customer_num = atoi(cmd[1]);
                for (int i = 0; i < number_of_resources; i++) {
                        resources[i] = atoi(cmd[i+2]);
                }
                if (!strcmp(cmd[0], "RQ")) {
                        request_resources(customer_num, resources);
                }
                else if (!strcmp(cmd[0], "RL")) {
                        release_resources(customer_num,  resources);
                }   
        }

        fclose(fp_cmd);
        fclose(fp_rslt);

        free(available);  /* The available amount of each resource */
        free(maximum);    /* the maximum demand of each customer */
        free(allocation); /* the amount currently allocated to each customer */
        free(need);       /* the remaining need of each customer */
        return 0;
}

/* Returns 0 if successful and –1 if unsuccessful */
int request_resources(int customer_num, int request[]) //TODO
{
        int n = number_of_customers;
        int m = number_of_resources;
        
        /* Step 1: Maximum check */
        for (int i = 0; i < m; i++) {
                /* Invalid request: Asking for more than promised */
                if (!(request[i] <= need[customer_num][i])) {
                        output_err_max(customer_num, request);
                        return -1;
                }
        }
        /* Step 2: Available check */
        for (int i = 0; i < m; i++) {
                /* Invalid request: Asking for more than possible */
                if (!(request[i] <= available[i])) {
                        output_err_av(customer_num, request);
                        return -1;
                }
        }

        /* 
        * Step 3: Simulate future state and check safety 
        * through temporary mirrors of the current state 
        */
        int tmp_av[m];
        int tmp_alloc[n][m];
        int tmp_need[n][m];

        /* curr state -> tmp state */
        copy_array(tmp_av, available, m);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        tmp_alloc[i][j] = allocation[i][j];
                        tmp_need[i][j] = need[i][j];
                }
        }

        /* Simulate tmp state */
        for (int i = 0; i < m; i++) {
                tmp_av[i] -= request[i];
                tmp_alloc[customer_num][i] += request[i];
                tmp_need[customer_num][i] -= request[i];
        }
        
        /* Check if it's safe or not */
        int finish[n];
        int work[m];
        memset(finish, 0, n * sizeof(int)); /* Initialize as all zero */
        copy_array(work, tmp_av, m); /* starts as AVAILABLE (temporary one) */

        if (!check_safety(tmp_av, (int **) tmp_alloc, (int**) tmp_need)) {
                output_err_unsafe(customer_num, request);
                return -1;
        }
        
        /* Is safe: Update the current state */
        copy_array(available, tmp_av, m);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        allocation[i][j] = tmp_alloc[i][j];
                        need[i][j] = tmp_need[i][j];
                }
        }

        output_succ_rq(customer_num, request);
        return 0; 
}

/* Returns 1 if safe, 0 if unsafe */
int check_safety(int av[], int *alloc[], int *nd[])
{
        int n = number_of_customers;
        int m = number_of_resources;

        int finish[n];
        int work[m];
        memset(finish, 0, n);
        copy_array(finish, av, m);

        int flag;
        int found;
        while (1) {
                found = 0;
                for (int i = 0; i < n; i++) {
                        flag = 1;
                        if (!(!finish[i] && arrcmp_leq(need[i], work, m))) {
                                flag = 0;
                                break;
                        }

                        if (flag) {
                                /* Array sum */
                                for (int j = 0; j < m; j++) {
                                        work[j] += alloc[i][j];
                                }
                                finish[i] = 1;
                                found = 1;
                        }
                }
                if (!found) {
                        for (int i = 0; i < n; i++){
                                if (!finish[i]) {
                                        return 0;
                                }
                        }
                        return 1;
                }                
        }        
}

void release_resources(int customer_num, int release[]) //TODO
{
        int m = number_of_resources;

        int qt;
        for (int i = 0; i < m; i++) {
                qt = release[i];
                if (qt > allocation[customer_num][i])
                        qt = allocation[customer_num][i];
                allocation[customer_num][i] -= qt;
                available[i] += qt;
        }

        /* Output success */
        "Release from customer %d the resources %d %d %d";
        fprintf(
                fp_rslt, 
                "Release from customer %d the resources ", 
                customer_num
                );
        for (int i = 0; i < number_of_resources; i++) {
                fprintf(fp_rslt, "%d ", release[i]);
        }
        fputs("\n", fp_rslt);
}

int count_lines(char *filename)
{
        int lines = 0;
        
        FILE *fp = fopen(filename, "r");
        if (!fp) {
                printf("\nCould not open file %s", filename);
                return lines;
        }
        
        char ch;
        while (!feof(fp)) {
                ch = fgetc(fp);
                if (ch == '\n') {
                        lines++;
                }
        }
        fclose(fp);
        return lines+1;
}

void read_customers(char *filename, int n, int m)
{
        FILE *fp = fopen(filename, "r");
        int num;
        for (int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        fscanf(fp,"%d,",&num);
                        maximum[i][j] = num;
                }
        }
        fclose(fp);
}

/* */
void read_resources(const char *argv[], int m)
{
        for (int i = 0; i < m; i++) {
                available[i] = atoi(argv[i+1]);
        }
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
			if (pc[i] == '\0') {
				break;
			}
		}
		cmd[pos] = malloc(size * sizeof(char));
		strcpy(cmd[pos], pc);
		pc = strtok(NULL, " ");
		pos++;
	}
	cmd[pos] = NULL;
}

int **alloc_matrix(int n, int m)
{
	int** matriz = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
		matriz[i] = calloc(m, sizeof(int));

	return matriz;
}

void copy_array(int *dst, int *src, int len)
{
        for (int i = 0; i < len; i++) {
                dst[i] = src[i];
        }
}

void output_resources(void)
{
        int n = number_of_customers;
        int m = number_of_resources;

        fputs("MAXIMUM\t| ALLOCATION\t| NEED\n", fp_rslt);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        if (j == m-1)
                                fprintf(fp_rslt, "%-7d | ",maximum[i][j]);
                        else 
                                fprintf(fp_rslt, "%d ", maximum[i][j]);
                }
                for (int j = 0; j < m; j++) {
                        if (j == m-1)
                                fprintf(fp_rslt, "%-10d | ",allocation[i][j]);
                        else 
                                fprintf(fp_rslt, "%d ", allocation[i][j]);
                }
                for (int j = 0; j < m; j++) {
                        if (j == m-1)
                                fprintf(fp_rslt, "%-4d | ", need[i][j]);
                        else 
                                fprintf(fp_rslt, "%d ", need[i][j]);
                }
                fputs("\n", fp_rslt);
        }
        
        fputs("AVAILABLE ", fp_rslt);
        for (int i = 0; i < m; i++) {
                fprintf(fp_rslt, "%d ", available[i]);
        }
        
}

void output_succ_rq(int customer_num, int request[])
{
        fprintf(
                fp_rslt, 
                "Allocate to customer %d the resources ", 
                customer_num
                );
        for (int i = 0; i < number_of_resources; i++) {
              fprintf(fp_rslt, "%d ", request[i]);
        }
        fputs("\n", fp_rslt);
}

void output_err_unsafe(int customer_num, int request[])
{
        fprintf(fp_rslt, "The customer %d request ", customer_num);
        for (int i = 0; i < number_of_resources; i++) {
                fprintf(fp_rslt, "%d ", request[i]);
        }
        fputs("was denied because result in an unsafe state\n", fp_rslt);
}

void output_err_max(int customer_num, int request[])
{
        fprintf(fp_rslt, "The customer %d request ", customer_num);
        for (int i = 0; i < number_of_resources; i++) {
                fprintf(fp_rslt, "%d ", request[i]);
        }
        fputs("was denied because exceed its maximum allocation\n", fp_rslt);
}

void output_err_av(int customer_num, int request[])
{
        fputs("The resources ", fp_rslt);
        for (int i = 0; i < number_of_resources; i++) {
                fprintf(fp_rslt, "%d ", available[i]);
        }
        fprintf(fp_rslt, "are not enough to customer %d request ", customer_num);
        for (int i = 0; i < number_of_resources; i++) {
                fprintf(fp_rslt, "%d ", request[i]);
        } 
        fputs("\n", fp_rslt);
}


/* Checks if every arr1[i] are LESS or EQUAL than their arr2[i] counterpart */
int arrcmp_leq(int arr1[], int arr2[], int n)
{
        for (int i = 0; i < n; i++) {
                if (!(arr1[i] <= arr2[i])) {
                        return 0;
                }
        }

        return 1;
}

void print_array(int *array, int n)
{
        printf("\n");
        for (int i = 0; i < n; i++) {
                printf("%d ", array[i]);
        }
        
}

void print_matrix(int **matrix, int n, int m)
{
        printf("\nMatrix:");
        for (int i = 0; i < n; i++) {
                printf("\n");
                for(int j = 0; j < m; j++) {
                        printf("%d ", matrix[i][j]);
                }
        }
}

void print_cmd(char **cmd)
{
        printf("\n");
        for (int i=0; cmd[i]; i++) {
                printf("%s ", cmd[i]);
        }
}
