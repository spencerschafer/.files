gcc -Wall -Wextra -Werror src/*.c -I.src/ -o rpn
echo "=========================================================================
Test 1:./rpn | cat -e\n"
touch test1 && ./rpn | cat -e >> test1
DIFF=$(diff answers/answer1 test1) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\nPassed 0 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi

echo "=========================================================================
Test 2:./rpn \"2 3 -\" \"5 6 +\" | cat -e\n"
touch test2 && ./rpn "2 3 -" "5 6 +" | cat -e >> test2
DIFF=$(diff answers/answer2 test2) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 1 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 3:./rpn \"2 -\" | cat -e\n"
touch test3 && ./rpn "2 -" | cat -e >> test3
DIFF=$(diff answers/answer3 test3) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 2 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 4:./rpn \"-\" | cat -e\n"
touch test4 && ./rpn "-" | cat -e >> test4
DIFF=$(diff answers/answer4 test4) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 3 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 5:./rpn \"2 5 6 -\" | cat -e\n"
touch test5 && ./rpn "2 5 6 -" | cat -e >> test5
DIFF=$(diff answers/answer5 test5) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 4 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 6:.rpn \"3 4 +\" | cat -e\n"
touch test6 && ./rpn "3 4 +" | cat -e >> test6
DIFF=$(diff answers/answer6 test6) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 5 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 7:./rpn \"2 4 + 8 *\" | cat -e\n"
touch test7 && ./rpn "2 4 + 8 *" | cat -e >> test7
DIFF=$(diff answers/answer7 test7) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 6 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 8:./rpn \"50 10 25 + -\" | cat -e\n"
touch test8 && ./rpn "50 10 25 + -" | cat -e >> test8
DIFF=$(diff answers/answer8 test8) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 7 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 9:./rpn \"1000 5 2 * /\" | cat -e\n"
touch test9 && ./rpn "1000 5 2 * /" | cat -e >> test9
DIFF=$(diff answers/answer9 test9) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 8 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 10:./rpn \"1000 3 %\" | cat -e\n"
touch test10 && ./rpn "1000 3 %" | cat -e > test10
DIFF=$(diff answers/answer10 test10) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 9 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 11:./rpn \"1000 0 /\" | cat -e\n"
touch test11 && ./rpn "1000 0 /" | cat -e > test11
DIFF=$(diff answers/answer11 test11)
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 10 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 12:./rpn \"1000 0 %\" | cat -e\n"
touch test12 && ./rpn "1000 0 %" | cat -e >> test12
DIFF=$(diff answers/answer12 test12) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 11 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 13:./rpn \"-1000 -1 *\" | cat -e\n"
touch test13 && ./rpn "-1000 -1 *" | cat -e >> test13
DIFF=$(diff answers/answer13 test13) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 12 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 14:./rpn \"-111 45 123 * 26 73 + + - 78 * -85 / 123 -\" | cat -e\n"
touch test14 && ./rpn "-111 45 123 * 26 73 + + - 78 * -85 / 123 -" | cat -e >> test14
DIFF=$(diff answers/answer14 test14) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 13 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "=========================================================================
Test 15:./rpn \"78 326 542 96 1452 36 965 % - * / - +\" | cat -e\n"
touch test15 && ./rpn "78 326 542 96 1452 36 965 % - * / - +" | cat -e >> test15
DIFF=$(diff answers/answer15 test15) 
if [ "$DIFF" != "" ] 
then
	echo "$DIFF\n"
	echo "Passed 14 of 15 tests-->Result: FAIL"
	rm test* rpn
	exit 1
else
	echo "OK :D"
fi
echo "Passed 15 of 15 tests-->Result: PASS"
rm test* rpn
