#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define DEBUG

#include "fogml_config.h"
float my_time_series[ACC_TIME_TICKS * ACC_AXIS];

#define LEARNING_SAMPLES    16

int main() {
	srand(time(NULL));
	printf("please input data\n");
	
	int ticks_stored = 0;
	int ret;
	bool learning = true;
	int learning_samples = 0;
	
	while (1) {
		ret = scanf("%f %f %f",	&my_time_series[ticks_stored * ACC_AXIS + 0], 
								&my_time_series[ticks_stored * ACC_AXIS + 1], 
								&my_time_series[ticks_stored * ACC_AXIS + 2]);
								
		if (ret < 3)
			break;
		
		#if DEBUG	
			printf("r=%d, storing tick %d: %5.2f %5.2f %5.2f\n", ret, ticks_stored,
				my_time_series[ticks_stored * ACC_AXIS + 0],
				my_time_series[ticks_stored * ACC_AXIS + 1],
				my_time_series[ticks_stored * ACC_AXIS + 2]);
		#endif
			
		ticks_stored++;

		if (ticks_stored == ACC_TIME_TICKS) {
			// printf("processing...\n");
			
			if (learning) {
				printf("learning...\n");

				fogml_learning(my_time_series);
				learning_samples++;

				if (learning_samples == LEARNING_SAMPLES) {
					learning_samples = 0;
					learning = false;
					printf("learning end\n");
				}
			}
			else {
				float score;
				fogml_processing(my_time_series, &score);
				// fogml_classification(my_time_series);
				
				printf("LOF Score = %5.2f, %s\n", score, (score > 2.5 ? "fail" : "ok"));
			}
						
			ticks_stored = 0;
		}
	}
}
