# RM-Algorithm in Linux
Rate Monotonic Algorithm using real time scheduler, timers, and multiprocessing on Linux.


In this project, the aim is to design a solution to system which composes of 4 tasks namely task
T1, T2, T3 and T4 using Rate Monotonic Algorithm on Linux. The solution must use real time scheduler,
timers, and multiprocess on Linux.

The parameters of each task are given as follows:
T1= {2, e1}
T2= {4, e2}
T3= {6, e3}
T4= {4, e4}

The value of e1 to e4 is left for your own decision but of course they must fulfill the RM sufficient , but
not necessary test (UT ≤ URM).

Component files of this project are TDummy1.c, TDummy2.c, TDummy3.c, TDummy4.c, partdsch.c.

--------------------------------------------------------------------------------------------------------------
# Run 4 Tasks Simultaneously with 1 Core CPU
![alt text](https://github.com/Ausrif-Dev/RM-algorithm/blob/0ce8c4cb8b62a592e75ae408182aebfec6052832/Run4Sim.PNG?raw=true)
![alt text](https://github.com/Ausrif-Dev/RM-algorithm/blob/2b92cfe8a1605e0c0b0c155151372d2379e9c8f6/Run4SimRes.PNG?raw=true)
--------------------------------------------------------------------------------------------------------------
# Use a Main Scheduler and 4 Core CPU
![alt text](https://github.com/Ausrif-Dev/RM-algorithm/blob/0986970182afdd43b5ed6e5919d601b564d90964/RunMainSched.PNG?raw=true)
![alt text](https://github.com/Ausrif-Dev/RM-algorithm/blob/2b92cfe8a1605e0c0b0c155151372d2379e9c8f6/Run4SimRes.PNG?raw=true)
