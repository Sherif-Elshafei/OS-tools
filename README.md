# Mutex and critical section
![A351_Mutex-and-Semaphore-in-OS2](https://github.com/Sherif-Elshafei/OS-tools/assets/4324447/06b9d1b3-4840-4ed4-8537-f99d350d274f)

## Why using threads?

Working on multiple processes is characterized by two things:

- Concurrency: where two or more processes work on separate things doing different things at the same time.
- Isolation: Processes are isolated from one another; meaning their memory is separate (so if one crashes, the other will work just fine).
We use threads to control multiple different flows of work that overlap in time. Working on multiple threads on the other hand is characterized by only concurrency. Meaning working on two different things concurrently but without the isolation (i.e. without separating memory frames). Threads have different call stacks but are in the same process, hence same memory space.

Due to being in the same memory space, one thread can write in the space of the other thread. That could be a grace or a disaster.

## What is a critical section?
Writing *i++* in HLL actually gets executed in three steps;
```
int temp;
temp = i+1;
i = temp;
```
If more that one thread is trying to update the value of *i* it could well happen that the three steps don't get completed before the context is switched to the other thread. As a result, the operation of that thread will be incomplete. Therefore, the section of the code that must be completed from top to bottom is called a critical section and must be exclusive to one thread hence the term MUTEX lock (or just lock). A thread won't be able to access a critical section unless its lock is released. A MUTEX lock is a computing abstraction that allows one thread to exclude other threads from a critical section of the code. A lock can only be owned to one thread until it releases it.

## Implementation (mutex3.cpp)
I use POSIX threads (aka pthreads). POSIX Threads is an API defined by the IEEE standard POSIX.1c, Threads extensions (IEEE Std 1003.1c-1995). POSIX threads are implemented with a pthread.h header and a thread library typically bundled as libpthread.
