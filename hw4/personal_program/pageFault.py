
import random
cin = [random.sample(range(10), 1) for _ in range(20)]
page_num = 3


def fifo(cin):
    count = 0
    frame = []
    for i in cin:
        if len(frame) < page_num:
            frame.append(i)
            count += 1
        else:
            if i not in frame:
                frame.append(i)
                frame = frame[1:]
                count += 1
    print('fifo', count)


def lru(cin):
    count = 0
    frame = []
    queue = []
    for i in cin:
        queue.append(i)
        if len(frame) < page_num:
            frame.append(i)
            count += 1
        else:
            queue = queue[1:]
            if i not in frame:
                nextFrame = frame
                for j in frame:
                    if j not in queue:
                        nextFrame.remove(j)
                        nextFrame.append(i)
                        count += 1
                        break
                frame = nextFrame
    print('lru', count)


def optimal(cin):
    count = 0
    frame = []
    for i in cin:
        if len(frame) < page_num:
            frame.append(i)
            count += 1
        else:
            if i not in frame:
                nextFrame = frame
                maxIndex = -1
                victim = -1
                for j in frame:
                    if j not in cin[cin.index(i):]:
                        victim = j
                        break
                    if cin[cin.index(i):].index(j) > maxIndex:
                        maxIndex = cin[cin.index(i):].index(j)
                        victim = j
                frame.remove(victim)
                frame.append(i)
                count += 1
                frame = nextFrame
        cin = cin[1:]
    print("optimal", count)


fifo(cin)
lru(cin)
optimal(cin)
