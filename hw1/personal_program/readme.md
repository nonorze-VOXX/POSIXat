# hw1

## Programming Problems

### 2.24 copies contents

#### build

`gcc copies.c -o copies.o`

#### run

`./copies.o file1 file2`

#### screenshot

![copies](./screenshot/copies.png)


### 3.19 timer

#### v1 share memory
##### build
`gcc command_timer_shm.c -o command_timer_shm.o`
##### run
`./command_timer_shm.o command`
##### screenshot
![timer_shm](./screenshot/command_timer_shm.png)

#### v2 pipe
##### build
`gcc command_timer_pipe.c -o command_timer_pipe.o`
##### run
`./command_timer_pipe.o command`
##### screenshot
![timer_pipe](./screenshot/command_timer_pipe.png)

### 3.21 Collatz
#### build
`gcc collatz.c -o collatz.o`
#### run
`./collatz.o 35`
#### screenshot
![collatz](./screenshot/collatz.png)

### 3.27 file copying by pipes

#### build

`gcc copies_pipe.c -o copies_pipe.o`

#### run

`./copies_pipe.o file1 file2`

#### screenshot

![copies_pipe](./screenshot/copies_pipe.png)