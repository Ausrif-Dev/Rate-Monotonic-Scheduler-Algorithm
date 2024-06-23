#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>
#include<sched.h>

int i; //Set up variables to be used in the program
int pid[3]; //Declare the pid array length for the four tasks

struct sched_param set_param; //setup scheduling parameter structure using the sched_param API

int main(){
	char *TaskAddressPointer[] = {"", "", NULL}; //SEtup pointer to the TDummy adress
	set_param.sched_priority = 50; //Set as the most high priority among the tasks for this main scheduler so that it won't be preempted

	i = sched_setscheduler(getpid(), SCHED_FIFO, &set_param); //assign to i the pid of the current task using the FIFO algorithm

	if(i == -1){ //Check PID if less than o is error
		perror("Unable to assign scheduler. [PID Error!]");
		exit(EXIT_FAILURE);
	}

	for(i=1; i<5; i++){ //Loop to run the Task file based on their PID number
		pid[i] = fork(); //Initiate fork process
		if(pid[i] == 0){ //Check if the PID is true to fork a chiold process
			if(i == 1)
				TaskAddressPointer[0] = "./TDummy1"; //Point to address containing the file TDummy1
			else if(i == 2)
				TaskAddressPointer[0] = "./TDummy2"; //Point to address containing the file TDummy2
			else if(i == 3)
				TaskAddressPointer[0] = "./TDummy3"; //Point to address containing the file TDummy3
			else if(i == 4)
				TaskAddressPointer[0] = "./TDummy4"; //Point to address containing the file TDummy4
			
		execv(TaskAddressPointer[0], TaskAddressPointer); //Execute the task file.
		}

		else if(pid[i] < 0){
			printf("Unable to initiate child process. [Incorrect PID!]\n"); //If unable to fin the pid in the rang or less than 0
			exit(1);
		}
	}

	wait(NULL); //Idle and loop
	return 0;
}