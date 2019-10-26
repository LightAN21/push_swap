# push_swap

This is a puzzle of sorting algortihms.

This project includes two programs: "checker" and "push_swap".

See more details in https://github.com/LightAN21/push_swap/blob/master/push_swap.en.pdf (basic rules at page 8)

### Installation
* git clone https://github.com/LightAN21/push_swap.git ~/push_swap
* cd ~/push_swap
* make
* make clean

### The "push_swap" program
The program "push_swap" takes integer arguments, then calculates and displays on the standard output the progam using Push_swap instruction language that sorts integer arguments received. The output steps should be as small as possible.

### The "checker" program
The program "checker" takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO. You can add operations: m, d, v, s for showing details of the sorting process.

### Auto run and check
A shell script is written in "random_num.sh". The script will generate a random list of positive integers, run the "push_swap" program, and check the output by "checker" program automatically. There will be 25 numbers in the number list as a default.

* sh random_num.sh

If you want to have different numbers in the input number list, you can change the number "25" in the first line of the script to the number you want.

### Example
```
ARG=`ruby -e "puts (1..75).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | ./checker -m $ARG
```

