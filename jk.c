read, write, open , close -  14-60
Zombie , orpan       - 62-90
sum of 2 no. as argument in cild to parent   -  92-134
lseek commad        - 136-154
producer consumer use posix      -   156-225
IPC use ordinay pipe      -  228-264
IPC use massage queue        - 266-316
Banker algoritm              -319-405
thread wit sared data and critical section       -407 - 474
semapore based thread syncroni                   - 477-521
fcfs , sjf ,priority , rr                       -524-654
first , best and worst fit                      -657-760

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
int main() {
    int fd1, fd2, n;
    char buffer[BUFFER_SIZE];

    // Open the source file for reading
    fd1 = open("input.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("Failed to open input.txt");
        return 1;
    }

    // Open/Create the destination file for writing
    fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("Failed to open output.txt");
        close(fd1);
        return 1;
    }

    // Read from input.txt and write to output.txt
    while ((n = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("Write error");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    if (n < 0) {
        perror("Read error");
    }

    // Close the files
    close(fd1);
    close(fd2);

    printf("File copied successfully.\n");

    return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process: PID = %d is exiting\n", getpid());
        //sleep(5); - orpan
        exit(0);  
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        printf("Parent sleeping for 10 seconds to create zombie...\n");
        sleep(10); `
        wait(NULL); 
        printf("Parent finished waiting. Child collected.\n");
        // exit(0); - orpan
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    if (num1 >= 50 || num2 >= 50) {
        printf("Please enter numbers less than 50.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        int sum = num1 + num2;
        printf("Child: Calculating sum %d + %d = %d\n", num1, num2, sum);
        exit(sum); // Return sum as exit status
    }
    else {
        // Parent process
        int status;
        wait(&status); // Wait for child to terminate

        if (WIFEXITED(status)) {
            int sum = WEXITSTATUS(status);
            printf("Parent: Received sum from child = %d\n", sum);
        }
    }
    return 0;
}


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 
int main() { 
int f;
char buff[10];
f = open("seeking", O_RDWR);
if (f < 0) { perror("open");
return 1; } // read first 10 bytes and print 
read(f, buff, 10);
write(1, buff, 10); // open the file "seeking" in read+write mode // move file pointer 10 bytes ahead from current 
lseek(f, 10, SEEK_CUR); // read next 10 bytes and print
read(f, buff, 10); 
write(1, buff, 10);
close(f);
return 0; }


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define SHM_NAME "/my_shm"
typedef struct {
    int data;
    int flag; // 0 = empty, 1 = full
} shared_data;
int main() {
    int fd;
    shared_data *shm_ptr;

    // Create shared memory
    fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        perror("shm_open");
        return 1;
    }

    // Set size of shared memory
    ftruncate(fd, sizeof(shared_data));

    // Map shared memory
    shm_ptr = mmap(NULL, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Initialize shared memory
    shm_ptr->flag = 0; // empty

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child: Consumer
        while (1) {
            if (shm_ptr->flag == 1) { // check if data is available
                printf("Consumer: Read data = %d\n", shm_ptr->data);
                shm_ptr->flag = 0; // mark empty
                break;
            }
        }
        munmap(shm_ptr, sizeof(shared_data));
        close(fd);
    }
    else {
        // Parent: Producer
        int value = 42;
        printf("Producer: Writing data = %d\n", value);
        shm_ptr->data = value;
        shm_ptr->flag = 1; // mark full

        wait(NULL); // wait for child
        munmap(shm_ptr, sizeof(shared_data));
        close(fd);
        shm_unlink(SHM_NAME); // remove shared memory
    }

    return 0;
}



#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int pipefd[2];  
    char write_msg[] = "Hello Child, this is Parent!";
    char read_msg[50];
    
    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        close(pipefd[1]); // Close write end
        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]);
    }
    else {
        // Parent Process
        close(pipefd[0]); // Close read end
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]);
    }

    return 0;
}


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
struct msg_buffer {
    long mtype;
    char mtext[100];
};
int main() {
    struct msg_buffer message;
    key_t key;
    int msgid;

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid < 0) {
        perror("msgget failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) { 
        // Child: Receiver
        sleep(1); // delay to allow parent to send first

        msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);
        printf("Child received: %s\n", message.mtext);
    } 
    else {
        // Parent: Sender
        message.mtype = 1;
        strcpy(message.mtext, "Hello from Parent!");

        msgsnd(msgid, &message, strlen(message.mtext) + 1, 0);
        printf("Parent sent message.\n");

        wait(NULL);

        // Remove queue after child receives message
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}



#include <stdio.h>
int main() {
    int n = 3; // number of processes
    int m = 4; // number of resource types

    int allocation[3][4] = {
        {1, 0, 2, 1},
        {1, 1, 0, 0},
        {0, 2, 1, 0}
    };

    int max[3][4] = {
        {3, 2, 2, 2},
        {1, 2, 2, 1},
        {1, 3, 2, 2}
    };

    // Case 1 → Safe condition
    int available_safe[4] = {2, 1, 2, 1};

    // Case 2 → Unsafe condition
    int available_unsafe[4] = {0, 0, 1, 0};

    int need[3][4];
    int finish[3] = {0, 0, 0};
    int safeSequence[3];

    int i, j, k;
    printf("\nCalculating Need Matrix...\n");

    // Calculate Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //-------------------------------------------
    // Function to test safe state
    //-------------------------------------------
    for (int caseType = 1; caseType <= 2; caseType++) {
        
        int available[4];
        for(i=0;i<m;i++) 
            available[i] = (caseType == 1) ? available_safe[i] : available_unsafe[i];

        for(i=0;i<n;i++) 
            finish[i] = 0;

        int count = 0;
        printf("\n========== Checking Case %d ==========\n", caseType);

        while (count < n) {
            int found = 0;
            for (i = 0; i < n; i++) {
                if (finish[i] == 0) {
                    for (j = 0; j < m; j++)
                        if (need[i][j] > available[j])
                            break;

                    if (j == m) {
                        for (k = 0; k < m; k++)
                            available[k] += allocation[i][k];

                        safeSequence[count++] = i;
                        finish[i] = 1;
                        found = 1;
                    }
                }
            }

            if (!found)
                break;
        }

        if (count == n) {
            printf("System is in SAFE STATE.\nSafe sequence: ");
            for (i = 0; i < n; i++)
                printf("P%d ", safeSequence[i]);
            printf("\n");
        } else {
            printf("System is in UNSAFE STATE! No safe sequence exists.\n");
        }
    }
    return 0;
}


#include <stdio.h>
#include <pthread.h>
int data[10] = {5, 12, 7, 9, 21, 3, 18, 10, 15, 6};
int sum = 0, max, min;
int shared_var = 0;
pthread_mutex_t lock;   // Mutex for critical section
void* calc_sum(void *arg) {
    for(int i = 0; i < 10; i++)
        sum += data[i];
    pthread_exit(NULL);
}
void* calc_max(void *arg) {
    max = data[0];
    for(int i = 1; i < 10; i++)
        if(data[i] > max)
            max = data[i];
    pthread_exit(NULL);
}
void* calc_min(void *arg) {
    min = data[0];
    for(int i = 1; i < 10; i++)
        if(data[i] < min)
            min = data[i];
    pthread_exit(NULL);
}
// Threads demonstrating critical section
void* update_shared_var(void* arg) {
    for(int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);  // start of critical section
        shared_var++;
        printf("Shared variable updated by thread %ld: %d\n", (long)arg, shared_var);
        pthread_mutex_unlock(&lock); // end of critical section
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t t1, t2, t3, t4, t5;

    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&t1, NULL, calc_sum, NULL);
    pthread_create(&t2, NULL, calc_max, NULL);
    pthread_create(&t3, NULL, calc_min, NULL);

    // Critical section demo threads
    pthread_create(&t4, NULL, update_shared_var, (void*)1);
    pthread_create(&t5, NULL, update_shared_var, (void*)2);

    // Wait for all threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    // Print results
    printf("\n=== Results from Threads ===\n");
    printf("Sum of array     : %d\n", sum);
    printf("Maximum value    : %d\n", max);
    printf("Minimum value    : %d\n", min);
    printf("Final Shared Var : %d\n", shared_var);

    pthread_mutex_destroy(&lock);

    return 0;
}



#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int shared_var = 0;  // shared resource
sem_t mutex;         // semaphore
void* thread_func(void* arg) {
    int id = (long)arg;   // Thread ID for display

    for(int i = 0; i < 5; i++) {
        sem_wait(&mutex);  // Enter critical section

        // Critical section
        shared_var++;
        printf("Thread %d updated shared_var to %d\n", id, shared_var);

        sem_post(&mutex);  // Exit critical section

        sleep(1);
    }

    pthread_exit(NULL);
}
int main() {
    pthread_t t1, t2;

    // Initialize semaphore to 1 (binary semaphore)
    sem_init(&mutex, 0, 1);

    // Create threads
    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nFinal value of shared variable: %d\n", shared_var);

    // Destroy semaphore
    sem_destroy(&mutex);

    return 0;
}



#include <stdio.h>
struct process {
    int pid, bt, wt, tat, priority, remaining_bt;
};
void fcfs(struct process p[], int n) {
    int i, time = 0;
    printf("\nGantt Chart: ");
    for (i = 0; i < n; i++) {
        printf("| P%d ", p[i].pid);
        p[i].wt = time;
        time += p[i].bt;
        p[i].tat = time;
    }
    printf("|\n");
}
void sjf(struct process p[], int n) {
    int i, j;
    struct process temp;
    
    // sort by burst time
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(p[j].bt > p[j+1].bt){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }

    fcfs(p, n);
}
void priority_scheduling(struct process p[], int n) {
    int i, j;
    struct process temp;
    
    // sort by priority
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(p[j].priority > p[j+1].priority){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }

    fcfs(p, n);
}
void round_robin(struct process p[], int n, int tq) {
    int time = 0, completed = 0, i;
    for(i = 0; i < n; i++)
        p[i].remaining_bt = p[i].bt;

    printf("\nGantt Chart: ");
    while (completed != n) {
        for(i = 0; i < n; i++) {
            if(p[i].remaining_bt > 0) {
                printf("| P%d ", p[i].pid);
                if(p[i].remaining_bt > tq){
                    time += tq;
                    p[i].remaining_bt -= tq;
                } else {
                    time += p[i].remaining_bt;
                    p[i].wt = time - p[i].bt;
                    p[i].remaining_bt = 0;
                    completed++;
                }
            }
        }
    }
    
    for(i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;
        
    printf("|\n");
}
void display(struct process p[], int n) {
    int i;
    float totalWT = 0, totalTAT = 0;
    
    printf("\nPID\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f", totalWT/n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT/n);
}
int main() {
    int n, i, choice, tq;
    struct process p[10], backup[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p[i].pid = i+1;
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &p[i].bt);
        
        printf("Enter Priority of P%d (lower number = Higher priority): ", i+1);
        scanf("%d", &p[i].priority);

        backup[i] = p[i];
    }

    do {
        // Reset data
        for(i = 0; i < n; i++) p[i] = backup[i];

        printf("\n====== CPU Scheduling Menu ======\n");
        printf("1. FCFS\n2. Shortest Job First (SJF)\n3. Priority Scheduling\n4. Round Robin\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: fcfs(p, n); display(p, n); break;
            case 2: sjf(p, n); display(p, n); break;
            case 3: priority_scheduling(p, n); display(p, n); break;
            case 4: 
                printf("Enter Time Quantum: ");
                scanf("%d", &tq);
                round_robin(p, n, tq); 
                display(p, n); 
                break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}



#include <stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main() {

    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    int b1[10], b2[10], b3[10];

    for (int i = 0; i < m; i++) {
        b1[i] = blockSize[i];
        b2[i] = blockSize[i];
        b3[i] = blockSize[i];
    }

    firstFit(b1, m, processSize, n);
    bestFit(b2, m, processSize, n);
    worstFit(b3, m, processSize, n);

    return 0;
}

