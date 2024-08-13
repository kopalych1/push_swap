#!/bin/bash


program=./push_swap
dir=tests/

min_operaions=2147483647
max_operaions=0
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
	if [ $n_of_operations -gt $max_operaions ]; then
		max_operaions=$n_of_operations
	fi
	if [ $n_of_operations -lt $min_operaions ]; then
		min_operaions=$n_of_operations
	fi
}

make
norminette src/ include/

echo "-------------------------------------"
for ((i = 1; i <= test_count; i++)); do
    echo "Running test $i"
    run_test
    echo "-------------------------------------"
done

average_moves=$(awk "BEGIN {print $total_moves / $test_count}")
echo "MIN number of operations: $min_operaions"
echo "MAX number of operations: $max_operaions"
echo "Average number of operations: $average_moves"

# make; ARG="$(python3 tests/generator.py)"; ./push_swap "$ARG"; ./push_swap "$ARG" | tests/checker_linux "$ARG"; ./push_swap "$ARG" | wc -l