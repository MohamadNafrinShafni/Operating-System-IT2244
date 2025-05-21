echo "Enter String_1"
read str1
echo "Enter String_2"
read str2

len1=${#str1}
len2=${#str2}

if [ $len1 -gt $len2 ]; then
    echo "$str1 is larger than $str2"
else
    echo "$str2 is larger than $str1"
fi

