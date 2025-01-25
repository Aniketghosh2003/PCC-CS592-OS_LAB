#1
# #!/bin/bash

# # Initialize the first two Fibonacci numbers
# a=0
# b=1

# read -p "Enter the number of terms: " n

# echo "$a"
# echo "$b"

# for ((i = 3; i <= n; i++)); do
#   c=$((a + b))   
#   echo "$c"   
#   a=$b   
#   b=$c           
# done


#2
# #!/bin/bash

# # Reatangle Area and Perimeter
# read -p "Enter the length of the rectangle: " length
# read -p "Enter the breadth of the rectangle: " breadth

# area=$((length * breadth))             
# perimeter=$((2 * (length + breadth)))  

# echo "The area of the rectangle is $area."
# echo "The perimeter of the rectangle is $perimeter."


#3
#!/bin/bash

read -p "Enter a 5-digit number: " num

sum=0

while [ "$num" -gt 0 ]; do
  temp=$((num % 10))  
  sum=$((sum + temp)) 
  num=$((num / 10))   
done

echo "The sum of the digits is $sum."


