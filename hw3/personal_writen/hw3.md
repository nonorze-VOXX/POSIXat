# hw3
110590002 王熯竑

## 7.8
Because acquiring a semaphore may put the process to sleep while it is waiting for the semaphore to become available.

## 8.20
- (a)(d)(f) can be made safely

> resource < need -> deadlock 

- (a) more resource-> decrease deadlock happen
- (b) less resource-> increase deadlock happen
- (c) more need-> increase deadlock happen
- (d) less need-> decrease deadlock happen
- (e) more need-> increase deadlock happen
- (f) less need-> decrease deadlock happen

## 8.27

- (a)
    1. compelete P4, available=(2,2,2,3)+(1,0,0,1) = (3,2,2,4)
    1. compelete P0, available=(3,2,2,4)+(1,2,0,2) = (4,4,2,6)
    1. compelete P1, available=(4,4,2,6)+(0,1,1,2) = (4,5,3,8)
    1. compelete P2, available=(4,5,3,8)+(1,2,4,0) = (5,7,7,8)
    1. compelete P3, available=(5,7,7,8)+(1,2,0,1) = (6,9,7,9)
- (b)
    1. compelete P2, available=(4,4,1,1)+(1,2,4,0) = (5,6,5,1)
    1. compelete P4, bvailable=(5,6,5,1)+(1,0,0,1) = (6,6,5,2)
    1. compelete P3, available=(6,6,5,2)+(1,2,0,1) = (7,8,5,3)
    1. compelete P1, available=(7,8,5,3)+(0,1,1,2) = (7,9,6,5)
    1. compelete P0, available=(7,9,6,5)+(1,2,0,2) = (8,11,6,7)


## 8.30


```js
Semaphore using = 1; 
int north_count = 0
int south_count = 0

function  north_farmer(){
    while 1
        wait(using)
        if(south_farmer!=0)
            signal(using)
        else
            break
    north_farmer++;
    signal(using)
    // passing
    wait(using)
    north_farmer--
    signal(using)
}
function  south_farmer(){
    while 1
        wait(using)
        if(north_farmer!=0)
            signal(using)
        else
            break
    south_farmer++;
    signal(using)
    // passing
    wait(using)
    south_farmer--
    signal(using)
}

```

## 9.15

- (a) external fragmentation
    - contiguous: when smaller allocation filled after other allocation, then external fragmentation will appear
    - paging: almost no external fragmentation
- (b) internal fragmentataion
    - contiguous: when allocation bigger than need, internal framentation will appear
    - paging: when allocation bigger than need, internal framentation will appear
- (c) ability to share code across processes
    - contiguous: size is not fixed, hard to share
    - paging: size is fixed, eazy to share

## 9.24
- (a) $2^15$ entries TODO~!
    2^17=131072 > 1GB/8KB = 125000
    32bit-17bit = 15bit
- (b) TODO
   