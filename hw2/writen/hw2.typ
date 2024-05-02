#import "@preview/timeliney:0.0.1"

= hw2
110590002 王熯竑

== 4.8
+ write file
+ task is quick than split new thread

== 4.10
not shared:(a) Rigister, (d) Stack memory
shared: (b) heap memory, (c) global memory

== 4.16
+ 1 thread will be created for input, 1 thread will be created for output. 
  - many thread use I/O will be blocked, so it is better to use 1 thread for I/O
+ 4 thread will be created for processing
  - four thread can process 4 task in same time, so it is better to use 4 thread for processing

== 5.14
+ each processing core has its own run queue:
  - advantage: 
    - each core can process task in parallel
  - disadvantage:
    - need to implement a mechanism to balance the load of each core
+ a single run queue is shared by all processing cores:
  - advantage: 
    - easy to implement
  - disadvantage:
    - if many task in run queue, it will be blocked

== 5.18
#timeliney.timeline(
  show-grid: true,
  {
    import timeliney: *

    headerline(group(..range(19).map(n=>"")))
      
  
    taskgroup({
      task($P_1$, (0, 3), style: (stroke: 2pt + black))
      task($P_2$, (3, 4),(16,19), style: (stroke: 2pt + black))
      task($P_3$, (4, 6),(8,9),(14,15), style: (stroke: 2pt + black))
      task($P_4$, (6, 8),(10,11),(15,16), style: (stroke: 2pt + black))
      task($P_5$, (9, 10), style: (stroke: 2pt + black))
      task($P_6$, (11, 14), style: (stroke: 2pt + black))
    })

    for i in range(20){
      let a = str((i)*5)
      milestone(
        at: i,
        style:(stroke:(dash: "dashed")) ,
        align(center,a)
      )
    }
  }
)
+ turenaround time:
  - $P_1$: 15
  - $P_2$: 95
  - $P_3$: 55
  - $P_4$: 55
  - $P_5$: 5
  - $P_6$: 15
+ waiting time:
  - $P_1$: 0
  - $P_2$: 75
  - $P_3$: 35
  - $P_4$: 35
  - $P_5$: 0
  - $P_6$: 0

== 5.22
+ the time quantum is 1 milisecond:\
   the CPU utilization is $(1+10)/((1+0.1) + (1+0.1)*10) = 90.90%$ 
+ the time quantum is 10 milisecond:\
   the CPU utilization is $(10+10)/((10 + 0.1) + (1+0.1)*10) = 94.78%$

== 5.25
+ FCFS\
  short process will be blocked by long process
+ RR \
  all process have same fixed time to run,
  then short process want run need to wait front process is queue
+ Multilevel feedback queues\
  all process process in first level queue,
  if the process is too long to run, it will be moved to next level queue.
  so short process can run in first level queue

  
== 6.7
- (a) when the stask length is 1, and two thread run pop in same time, will happen race condition, and segfault
- (b) let the stack function is atomic, so the race condition will be fixed

== 6.15
1. loss of responsiveness: disabling interrupts will let single-processor system can't response to other task. In user level will look like freeze, it is not good for user experience.
2. system stablility: if the interrupt is disabled, the system can't response to hardware interrupt, so the system will be unstable.

== 6.18
the aquire a lock request will be enqueue to a waiting queue.
when acquired the lock, the thread will be blocked by waiting queue,
when unlock the lock, make next request have request.