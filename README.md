# Operating Systems Projects: Threading & IPC

This repository contains two projects demonstrating core operating system concepts:
1. **Project A**: Multi-threaded Banking System (with Deadlock Handling)
2. **Project B**: Inter-Process Communication (IPC) using Pipes

## Project A: Multi-Threading Implementation (Four Phases)

### Overview
A banking system simulation demonstrating thread operations, synchronization, deadlock scenarios, and resolution.

#### Phase Structure:
1. **Basic Thread Operations**
   - Thread creation for concurrent transactions
   - Unsafe account balance updates
2. **Resource Protection**
   - Mutex implementation for account access
   - Synchronized deposits/withdrawals
3. **Deadlock Creation**
   - Simulated deadlock through unordered locking
   - Multiple account transfer deadlock scenario
4. **Deadlock Resolution**
   - Resource ordering implementation

### Code Structure

/multi_threading
├── basic_multi_threading.c # Shows multi threading creation and account balance updation
├── basic_multi_threading # exicutable of basic_multi_threading.c
├── resource_protection.c # Implements mutex for synchronized deposits/withdrawals
├── resource_protection # exicutable of resource_protection.c
├── deadlock_creation.c # Simulate deadlock 
├── deadlock_creation # exicutable of deadlock_creation.c
├── deadlock_preventation.c # Deadlock resolution using resource ordering
└── deadlock_preventation # exicutable of deadlock_preventation.c


### Build & Run
run these executables one by one to correctly understand the output.
```bash
cd multi_threading
./basic_multi_threading
./deadlock_preventation
./deadlock_preventation
./resource_protection
```


## Project B: IPC usign Pipes

### Overview
Demonstartes process communication through:
1. Costum consumer-producer programs
2. Shell pipeline utilities

#### Implementation: 
**producer.c**
   - Generates numerical data with occasional invalid entries
   - Writes to stdout
**consumer.c**
   - Reads from stdin
   - Sums valid integers
   - Handles invalid input
**count_txt_files.sh**
   - Shell script to count the number of txt files in the current dir
   - User comand line utility (ls, awk, grep, wc)

### Code Structure

/IPC
├── consumer.c # Reads from stdin
├── producer.c # Writes to stdout
├── count_txt_files.sh # Count the number of txt files in the dir
├── file.txt # A txt file
└── file2.txt # A txt file


### Build & Run
```bash
cd IPC
./producer | ./consumer
sh count_txt_files.sh
```

# Expected Output: 
Invalid input: abc
Total: 52
2

### Data flow diagram 
Producer -> [Pipe] -> Consumer
ls -> awk -> grep -> wc
