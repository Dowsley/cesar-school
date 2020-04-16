def fizzbuzz(n):
    m=n%3
    l=n%5
    if m==0 and l!=0:
        return "Fizz"
    if m!=0 and l==0:
        return "Buzz"
    if m==0 and l==0:
        return "FizzBuzz"
    if m!=0 and l!=0:
        return n

