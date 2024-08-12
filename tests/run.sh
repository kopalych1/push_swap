#!/bin/bash


program=./push_swap
dir=tests/

test_count=100
numbers_amount=$2
if [ $# -eq 1 ]; then
	test_count=$1
fi
if [ $# -eq 2 ]; then
	test_count=$1
fi
total_moves=0

run_test() {
	ARG=$(python3 ${dir}generator.py $numbers_amount)
	OUTPUT=$($program "$ARG")
	echo "$ARG" > logs/latest_test.log
	echo "$OUTPUT" >> logs/latest_test.log

	n_of_operations=$(echo "$OUTPUT" | wc -l | tr -d ' ')
	total_moves=$((total_moves + n_of_operations))

	$program "$ARG" | ${dir}/checker_linux "$ARG"
	echo "Operations: $n_of_operations"
}

make
norminette src/

echo "-------------------------------------"
for ((i = 1; i <= test_count; i++)); do
    echo "Running test $i"
    run_test
    echo "-------------------------------------"
done

average_moves=$(awk "BEGIN {print $total_moves / $test_count}")
echo "Average number of operations: $average_moves"