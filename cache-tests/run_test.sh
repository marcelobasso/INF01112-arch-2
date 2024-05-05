echo "Runing tests..."
sudo perf stat -e instructions,cycles,mem_load_retired.l1_hit,mem_load_retired.l1_miss,mem_load_retired.l2_hit,mem_load_retired.l2_miss,mem_load_retired.l3_hit,mem_load_retired.l3_miss,mem_load_retired.l3_hit ./main
