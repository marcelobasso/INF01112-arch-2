#!/bin/bash


size=$(cat /sys/devices/system/cpu/cpu0/cache/index0/size)
typeCache=$(cat /sys/devices/system/cpu/cpu0/cache/index0/type)
sets=$(cat /sys/devices/system/cpu/cpu0/cache/index0/number_of_sets)
ways=$(cat /sys/devices/system/cpu/cpu0/cache/index0/ways_of_associativity)
coherency=$(cat /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size)

echo "Cache Level-1"
echo "Type: $typeCache"
echo "Size: $size"
echo "Number of Sets: $sets"
echo "Ways of Associativity: $ways"
echo "Coherence line-size: $coherency"
echo " "

size=$(cat /sys/devices/system/cpu/cpu0/cache/index1/size)
typeCache=$(cat /sys/devices/system/cpu/cpu0/cache/index1/type)
sets=$(cat /sys/devices/system/cpu/cpu0/cache/index1/number_of_sets)
ways=$(cat /sys/devices/system/cpu/cpu0/cache/index1/ways_of_associativity)
coherency=$(cat /sys/devices/system/cpu/cpu0/cache/index1/coherency_line_size)

echo "Cache Level-1"
echo "Type: $typeCache"
echo "Size: $size"
echo "Number of Sets: $sets"
echo "Ways of Associativity: $ways"
echo "Coherence line-size: $coherency"

echo " "
size=$(cat /sys/devices/system/cpu/cpu0/cache/index2/size)
typeCache=$(cat /sys/devices/system/cpu/cpu0/cache/index2/type)
sets=$(cat /sys/devices/system/cpu/cpu0/cache/index2/number_of_sets)
ways=$(cat /sys/devices/system/cpu/cpu0/cache/index2/ways_of_associativity)
coherency=$(cat /sys/devices/system/cpu/cpu0/cache/index2/coherency_line_size)

echo "Cache Level-2"
echo "Type: $typeCache"
echo "Size: $size"
echo "Number of Sets: $sets"
echo "Ways of Associativity: $ways"
echo "Coherence line-size: $coherency"
echo " "

size=$(cat /sys/devices/system/cpu/cpu0/cache/index3/size)
typeCache=$(cat /sys/devices/system/cpu/cpu0/cache/index3/type)
sets=$(cat /sys/devices/system/cpu/cpu0/cache/index3/number_of_sets)
ways=$(cat /sys/devices/system/cpu/cpu0/cache/index3/ways_of_associativity)
coherency=$(cat /sys/devices/system/cpu/cpu0/cache/index3/coherency_line_size)

echo "Cache Level-3"
echo "Type: $typeCache"
echo "Size: $size"
echo "Number of Sets: $sets"
echo "Ways of Associativity: $ways"
echo "Coherence line-size: $coherency"