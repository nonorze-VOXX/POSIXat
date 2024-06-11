# hw4
110590002 王熯竑

## 10.21[WIP*]
$(1-x)*100+x*(0.3*8*10^6+0.7*20*10^6)$
$ x < 0.00000609$
## 10.24
### FIFO
page fault: 15
### LRU
page fault: 16
### OPT
page fault: 11

## 10.37

thrashing

- cause: process no have enough pages
- system detect thrashing: detect page fault rate is high
- system can do: remove program which priority is low


## 11.13

- FCFS:13011
- SCAN: 7492
- C-SCAN: 4918

## 11.20
- (a) 1+1=2 blocks
- (b) 4+1+3+1=9 blocks

## 11.21
- (a) single block :
    - RAID1: can read from N disk
    - RAID5: must read check disk and one data disk
- (b) mutiple contiguous blocks :
    - RAID1: need to read from N disk
    - RAID5: must read check disk and N-1 data disk

## 14.14
let Z=start block number
- contiguous:
    - (a) 
        physical block number = Z +logical address/512
        displacement into block = logical address % 512
    - (b) 
        1 block
- linked:
    - (a) 
        the count of phycial blocks = logical address/511
        from Z , through the blocks to get all physical block
        displacement into the block = logical address % 511 +1
    - (b) 
        5 block
- indexed:
    - (a) 
        the count of phycial blocks = logical address/512
        for given index,check the index block
        displacement into the block = logical address % 512
    - (b) 
        2 block


## 14.15
12*8KB= 96KB
single indirect: (8KB/4B) * 8KB =  16MB
double indirect: ((8KB/4B) * 8KB/4B) * 8KB = 32GB
triple indirect: (((8KB/4B) * 8KB/4B) * 8KB/4B) *8KB = 64TB
sum: 96KB+16MB+32GB+64TB= 64.0320161TB