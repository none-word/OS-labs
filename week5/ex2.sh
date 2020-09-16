#!/bin/bash

if test ! -f ex2
then
  echo 0 > ex2
fi

if ln ex2 ex2.lock
then

  for i in `seq 1 10`:
  do 

    last=`tail -1 ex2`
    last=$((last + 1))
    echo $last >> ex2

  done

  rm ex2.lock
fi
