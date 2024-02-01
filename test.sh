#!/usr/bin/env bash

prettyPrint() {
	echo -e "\n$1\n"
}

# Call make
make clean
make -f Makefile

touch temp.txt

# Parser test
for file in ./tests/input/*.txt; do
	number=$(echo $(basename $file) | tr -dc '0-9');
	(./basic-compiler -p -i $file) > temp.txt
	output=$(diff temp.txt tests/output/output"$number".txt)

	if (($?)); then
		prettyPrint "Test $number has failed"
		rm temp.txt
		exit 1
	fi

done

rm temp.txt

prettyPrint "Tests have passed"

