#!/usr/bin/env bash

my_handler() {
    echo "my_handler"
}

trap 'kill ${!}; my_handler' SIGUSR1

while true
do
    tail -f /dev/null & wait ${!}
done
