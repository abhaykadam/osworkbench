#define INIT_PROCESS_C switch (proc_id){\
case 1:\
init_p1 (VMachine->scheduler);\
break;\
case 2:\
init_p2 (VMachine->scheduler);\
break;\
} 
