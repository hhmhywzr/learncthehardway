echo "Running unit tests:"

for in in tests/*_tests
do
	if test -f $i
	then
		if sudo $VALGRIND ./$i 2>> tests/tests.log
		then
			echo $i pass
		else
			echo "ERROR in test $i: here's tests/tests.log"
			echo "------"
			tail tests/tests.log
			exit 1
		fi
	fi
done

echo ""
