def is_prime(num):
    for i in range (2, num):
        if num % i == 0 :
            return False
    return True
    

number = int(input("Enter number : "))
count = 0

for i in range(2, number):
    if(is_prime(i)) :
        print(i," ")
        count = count +1
print("Total Count : ", count)
        
