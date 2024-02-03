# Priority Inversion

This project has been written using STM32CubeIde. 

##

### HighTask
high priority
takes semaphore

### NormalTask
medium priority
no semaphore

### LowTask
low priority 
takes semaphore
waits for button to realease semaphore

##

- high task executes, acquires and releses semphore
- medium task runs
- control goes to low task that acquire sempahore and waits for button to be pressed (CRITICAL SECTION)
- high task resumes and preemepts the low task
- until semaphore is acquired by low task high task mnust waits for it
- medium task will resume and preempts the low task
- medium task does not needs sempahore so it will keep executing every 500 ms
- even if i press the button the low task has to wait the medium task to finish its execution
- also high task will have to wait for medium task
- PRIORITY INVERSION
- when button is pressed low task will continue execution 
- releases semaphore and high task will continue from waiting point 
- medium task runs
- high tasks executes, acquires and releases semaphore
- time to do this is less than 500 ms so low task will run till medium task is suspended and waiting for 500 ms
- low task waits fot the event 
- medium task will come out of suspension and preempt the low task
- high task is waiting for it 500 ms to complete
- high task will resume and tryies to acquiere semaphore
- it has to wait since medium task will keep preempting the low task at 500 ms
- same thing whever the button is pressed 
