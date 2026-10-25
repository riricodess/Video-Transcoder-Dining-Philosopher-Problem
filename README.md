# Video Transcoder — Dining Philosophers Problem

## Overview

This project demonstrates the Dining Philosophers synchronization problem using C, POSIX threads, and mutex locks. It models video transcoder workers sharing hardware resources while processing video frames.

## Use Case

A video transcoder converts video frames from one format to another using shared hardware resources such as encoder and decoder units. Each worker thread needs two resources simultaneously, similar to a philosopher requiring two forks to eat.

If every worker acquires one resource and waits for another, deadlock can occur. This problem helps explain resource allocation and synchronization in multimedia processing.

## Technologies Used

- C Programming
- POSIX Threads (`pthread`)
- Mutex Locks
- Operating Systems — Process Synchronization and Deadlock

## How It Works

1. Initialize two mutex locks representing shared resources.
2. Ask the user to enter a worker ID (`0` or `1`).
3. Create a transcoder thread.
4. Acquire the required resource locks.
5. Display a message when the thread acquires both locks and processes a frame.
6. Release both locks and wait for the thread to finish.

## Compilation and Execution

Compile the program on Linux or Ubuntu:

```
gcc dining.c -o dining -pthread
```

Run the program:

```
./dining
```

Enter `0` or `1` when prompted.

## Sample Output

```
Enter worker ID (0 or 1): 0
Transcoder Thread 0: Acquired locks & processing frame.
```

## Applications

- Video transcoding and multimedia processing
- Shared encoder and decoder resources
- Database lock management
- Systems where multiple tasks require shared resources

## Conclusion

The project illustrates how mutex locks coordinate access to shared hardware resources and introduces the synchronization and deadlock challenges associated with concurrent processing.

Save this as `README.md` and upload it to your `Video-Transcoder-Dining-Philosophers` repository. The compile commands match your `dining.c` file.
