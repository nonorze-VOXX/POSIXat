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
      task($P_3$, (4, 6),(8,9),(10,11), style: (stroke: 2pt + black))
      task($P_4$, (6, 8),(14,16), style: (stroke: 2pt + black))
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
  - $P_3$: 35
  - $P_4$: 55
  - $P_5$: 5
  - $P_6$: 15
+ waiting time:
  - $P_1$: 0
  - $P_2$: 75
  - $P_3$: 15
  - $P_4$: 30
  - $P_5$: 0
  - $P_6$: 0
