#!/bin/bash

# Get the list of message queues and extract the second column
queue_list=$(ipcs -q | awk 'NR > 2 {print $2}')

# Iterate over the values and remove message queues
for val in $queue_list; do
    ipcrm -q "$val"
done

queue_list=$(ipcs -m | awk 'NR > 2 {print $2}')

# Iterate over the values and remove message queues
for val in $queue_list; do
    ipcrm -m "$val"
done

echo "All message queues cleared."
