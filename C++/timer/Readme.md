# Timer

* timer is a tool using <chrono>, providing high resolution time of which the unit is ms.

## functions

* start()
  * start timing.
  * it must be firstly called.
* end()
  * end timing.
  * it must be finally called before getting timing result.
* pause()
  * pause timing
* proceed()
  * continue timing
* result_ms()
  * get timing result, whose unit is ms.

* print_current_time()
  * print current time, including date, hour, min, sec and millisecond