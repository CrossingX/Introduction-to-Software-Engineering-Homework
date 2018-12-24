## 自顶向下，逐步求精
<br/>自顶向下设计是一种分析问题的方法，可以被应用在面向过程的编程中。简单的说，自顶向下就是将一个大问题先分解为若干个小问题，在将每个小问题继续分解，直到不能再分解或者可以轻易实现为止。应用在计算机领域的编程过程中，则是将主程序分为若干个模块，实现了这些模块，就可以实现整个程序，然后再用同样的方法对待每一个模块，这样，实现每一个小模块就意味着实现最终的大模块。
![](images\lab09\1.PNG)
<br/>自顶向下，就是将问题不断分解为小的模块；逐步求精，你可以把它理解为将各个小模块实现和优化的过程。
<br/>下面我们用生活中常见的洗衣机的例子来说明这个方法。我们的任务是实现洗衣机的洗衣程序。
<br/>Level 1:
<br/>首先先将整个洗衣程序分解为以下几个大步骤：
1. water in
2. soak
3. wash 
4. water out
5. rinse
6. dewater
7. water out
8. halt
<br/>Level 2:
<br/>然后利用上面已经实现的模块，将上面各个步骤的实现用伪代码表示出来：
<br/>water in:
<br/>WHILE getwatervolume() < standard_watervolume
<br/>    waterinswitch(open)
<br/>    IF timecounter() > max_waterin_time
<br/>        halt(failure)
<br/>ENDWHILE
<br/>waterinswitch(close)
<br/>
<br/>soak:
<br/>WHILE timecounter() < standard_soaking_time
<br/>ENDWHILE
<br/>
<br/>wash:
<br/>WHILE timecounter() < standard_washing_time
<br/>    WHILE timecounter() < each_direction_time
<br/>        motorrun(left)
<br/>    ENDWHILE
<br/>    motorrun(stop)
<br/>    WHILE timecounter() < each_direction_time
<br/>        motorrun(right)
<br/>    ENDWHILE
<br/>    motorrun(stop)
<br/>ENDWHILE
<br/>
<br/>waterout:
<br/>WHILE getwatervolume() > 0
<br/>    wateroutswitch(open)
<br/>    IF timecounter() > max_waterout_time
<br/>       halt(failure)
<br/>ENDWHILE
<br/>wateroutswitch(close)
<br/>
<br/>rinse:
<br/>FOR each time in standard_rinsing_number_times
<br/>    WHILE getwatervolume() < standard_watervolume
<br/>        waterinswitch(open)
<br/>       IF timecounter() > max_waterin_time
<br/>           halt(failure)
<br/>    ENDWHILE
<br/>    waterinswitch(close)
<br/>    WHILE timecounter() < standard_rinsing_time
<br/>        WHILE timecounter() < each_direction_time
<br/>            motorrun(left)
<br/>        ENDWHILE
<br/>        motorrun(stop)
<br/>    WHILE timecounter() < each_direction_time
<br/>       motorrun(right)
<br/>   ENDWHILE
<br/>   motorrun(stop)
<br/>ENDWHILE
<br/>WHILE getwatervolume() > 0
<br/>   wateroutswitch(open)
<br/>   IF timecounter() > max_waterout_time
<br/>       halt(failure)
<br/>ENDWHILE
<br/>wateroutswitch(close)
<br/>ENDFOR
<br/>
<br/>dewatering:
<br/>WHILE timecounter() < standard_dewatering_time
<br/>    WHILE timecounter() < each_direction_time
<br/>        motorrun(left)
<br/>    ENDWHILE
<br/>    motorrun(stop)
<br/>    WHILE timecounter() < each_direction_time
<br/>        motorrun(right)
<br/>    ENDWHILE
<br/>    motorrun(stop)
<br/>ENDWHILE
<br/>
<br/>waterout:
<br/>WHILE getwatervolume() > 0
<br/>    wateroutswitch(open)
<br/>    IF timecounter() > max_waterout_time
<br/>       halt(failure)
<br/>ENDWHILE
<br/>wateroutswitch(close)
<br/>
<br/>halt(success)