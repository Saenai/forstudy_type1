@echo off
  set begin = %time%
  call :time2sec %begin%
  set t1=%ns%
  CPP <in.txt >out.txt
  set end = %time%
  call :time2sec %end%
  set t2=%ns%
  set /a tdiff=%t2% - %t1%
  echo run time = %tdiff% ms
  
  :time2sec
  set tt=%1
  set hh=%tt:~0,2%
  set mm=%tt:~3,2%
  set ss=%tt:~6,2%
  set ms=%tt:~9,2%
  set /a ns=((%hh%*60+%mm%)*60+%ss%)*1000+%ms%