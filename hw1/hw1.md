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
# 3.12
# 3.18