
ANSWER:-
9.#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 number1 number2 ... numberN"
  exit 1
fi

numbers=("$@")
sorted=$(printf "%s\n" "${numbers[@]}" | sort -nr)

echo "Numbers sorted in descending order:"
echo "$sorted"

10.
#!/bin/bash

echo "Enter Student Name:"
read name

echo "Enter marks for Subject 1:"
read sub1
echo "Enter marks for Subject 2:"
read sub2
echo "Enter marks for Subject 3:"
read sub3

total=$((sub1 + sub2 + sub3))
average=$((total / 3))

get_grade() {
  local marks=$1
  if [ $marks -ge 90 ]; then
    echo "A+"
  elif [ $marks -ge 80 ]; then
    echo "A"
  elif [ $marks -ge 70 ]; then
    echo "B"
  elif [ $marks -ge 60 ]; then
    echo "C"
  elif [ $marks -ge 50 ]; then
    echo "D"
  else
    echo "F"
  fi
}

grade1=$(get_grade $sub1)
grade2=$(get_grade $sub2)
grade3=$(get_grade $sub3)

echo ""
echo "Marksheet for $name"
echo "Subject 1: $sub1   Grade: $grade1"
echo "Subject 2: $sub2   Grade: $grade2"
echo "Subject 3: $sub3   Grade: $grade3"
echo "Total Marks: $total"
echo "Average Marks: $average"


11.
#!/bin/bash

echo "Enter a number:"
read num

echo "Multiplication table for $num:"

for i in {1..10}
do
  echo "$num x $i = $((num * i))"
done

12.
#!/bin/bash

echo "Enter a number:"
read n

# Validate input is a non-negative integer
if ! [[ "$n" =~ ^[0-9]+$ ]]; then
  echo "Error: Please enter a non-negative integer."
  exit 1
fi

fact=1

for (( i=2; i<=n; i++ ))
do
  fact=$((fact * i))
done

echo "Factorial of $n is $fact"

