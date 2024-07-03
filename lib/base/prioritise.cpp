/******************************************************************************

	int setThreadHighPriority()
	
	A pthreads thread can call this to make itself run at higher priority
	
	returns zero if successful, non zero if an error occurs

******************************************************************************/

#include <pthread.h>
#include <sched.h>
#include <lib/base/prioritise.h>

#define HIGHEST_PRIORITY	(sched_get_priority_min(SCHED_FIFO))	// Lowest numeric value
#define HIGHER_PRIORITY		(sched_get_priority_min(SCHED_FIFO) + (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO)) / 4)
#define AVERAGE_PRIORITY	(sched_get_priority_min(SCHED_FIFO) + (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO)) / 2)
#define LOWER_PRIORITY		(sched_get_priority_min(SCHED_FIFO) + (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO)) * 3 / 4)
#define LOWEST_PRIORITY		(sched_get_priority_max(SCHED_FIFO))	// Highest numeric value

int setThreadHighPriority() {
	// Set pthread thread priority and set scheduling policy to SCHED_FIFO
	struct sched_param param;
	param.sched_priority = HIGHER_PRIORITY;
	return pthread_setschedparam(pthread_self(), SCHED_FIFO, &param);
}
