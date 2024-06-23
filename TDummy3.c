#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sched.h>

timer_t gTimerid; //initiate timer id variable

void start_t(){ //Initialise the period
	struct itimerspec time_value;
	time_value.it_value.tv_sec = 6;
	time_value.it_value.tv_nsec = 0;
	time_value.it_interval.tv_sec = 6;
	time_value.it_interval.tv_nsec = 0;
	timer_create(CLOCK_MONOTONIC, NULL, &gTimerid);
	timer_settime(gTimerid, 0, &time_value, NULL);
}

void delay(float num_sec){
	// Setup the execution time
	long msec = 1000000 * num_sec;
	clock_t c_start = clock();
	while (clock() < c_start + msec);
}

void Start_Task(){
	struct timespec tstart, tend; //Initialise the structure for the timer
	clock_gettime(CLOCK_MONOTONIC, &tstart); //Start Rate Monotonic
	float a = 10.0;
	float b = 2.0;
	float result;
	result = a*b; //Calculate the dummy process and the execution time in the period
	delay(0.2); //Use 0.2 execution time for the third task
	clock_gettime(CLOCK_MONOTONIC, &tend); //End task and print the results
	int64_t c = ((int64_t)tend.tv_sec * 1000000000 + (int64_t)tend.tv_nsec) - ((int64_t)tstart.tv_sec * 1000000000 +
	(int64_t)tstart.tv_nsec);
	printf("|Task 3\tRun for: %.1fs|\t|Mult of 10 and 2 is %.1f |\n", c, (c * 0.000000001), result);
}


void timer_handler(){ //This is the timer handler to get the start signal and send end signal
	printf("|Initiate Task 3... PID: %d|\n", getpid());
	Start_Task(); //Jump to Start_Task
	printf("|Task 3 Execution Done...|\n");
	(void) signal(SIGALRM, timer_handler); // Send and get signal
}

int main(){
	struct sched_param set_param; //setup scheduling parameter structure using the sched_param API
	set_param.sched_priority = 10; //Priority of the task is T1>T2/T4>T3 I set the the priority as 30, 20, 10, 20
	
	int i = sched_setscheduler(0, SCHED_FIFO, &set_param); //sets the scheduling policy of the calling process to SCHED_FIFO with the priority specified in the set_param structure
	if(i == -1){ //Check for correct i
	fprintf(stderr, "Priority Error! [Unable to Assign Priority!]\n");
	exit(1);
}

(void) signal(SIGALRM, timer_handler); //If all good, send signal to timer_handler, function call
start_t(); //Function call to declare the period of the task

	while(1){
		pause(); //Loop
	}
}