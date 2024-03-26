# 1.16

## (a)
CPU connect DMA
DMA connect devices
if I/O need to transfer data
I/O send request to DMA, CPU no need to join the I/O

## (b)
DMA will send signal to CPU when I/O.
if CPU no receive signal, CPU know operation is compelete.

## (c)
- if CPU and DMA use same resource, they will interference.

# 2.15
- shared memory model
    - strengths
        - efficiency: shared memory is faster
        - low price: use memory is lower price than message
        - flex: no need to serialize and deserialize
    - weakness
        - sync: need signal to limit memory access or race 
        - limited scalability: the shared memory is limit by avaliable memory 
        - security risks: shared memory will cause a process access or break other process

- message passing model
    - strengths
        - safty: message passing provides more safe communication
        - modularity: can setting api and use api to extend
        - ability of extend:  every process have own memory to message queue
    - weakness
        - weak efficiency: need to seriialize large data spend many time
        - complexity: message passing require complex system to implment it 
# 2.19
## adventage of the microkernel
modularity can updated without affecting the entire system
if service is broken, the error will not affect other service
it change eazy, that can fit changing requirements

## disadventages of the microkernel
the performance will waste on communication between service
design the system will more complexity
the hardware design implement will be more hard

## the user progran and system service interact
user program send request to the service through IPC
the service get request and access hardware or something
when process done, response result to user program



# 3.12
CPU save currently process state to PCB1
load state of other process from PCB2
excute until process switch
save state to PCB2
reload state from PCB1




# 3.18
## ordinary pipes are more suitable than named pipes
when child and parent process communicate, ordinary pipes is more suitable than named pipes
## named pipes are more suitable than ordinary pipes
when communication between persistent process, named pipes are more suitable than ordinary pipes