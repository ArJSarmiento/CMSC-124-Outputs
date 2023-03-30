(begin
    (display "Programming Exercise 3")
    (newline)
    (display "This program is a collection of functions that perform various tasks using the scheme language")
    (newline)
    (display "Sean Gabriel Bayron")
    (newline)
    (display "Student Number: 2021-04354")
    (newline)
    (display "Arnel Jan Sarmiento")
    (newline)
    (display "Student Number: 2021-05094")
    (newline)
    (display "Date: 2023-3-28")
    (newline)
)


; A - returns the factorial of a number
(define (Factorial n)
  (if (< n 0) ; error if n is less than 0
      (error "Please input 0 or positive integers")
  (if (= n 0)
      1
      (* n (Factorial (- n 1))))))


; B - returns a set of numbers based on the T-Ice pattern from 1 to n
(define (T-Ice n)
  (if (< n 0)
      (begin
        (error "Please input numbers greater than 0"))
      (if (= n 1)
          (display "1 ")
          (if (and (= (remainder n 2) 0) (= (remainder n 3) 0)) ;if n is divisible by 2 and 3, then display T-ICE
              (begin
                (T-Ice (- n 1))
                (display "T-ICE "))
              (if (= (remainder n 2) 0) ; if n is divisible by 2, then display T
                  (begin
                    (T-Ice (- n 1))
                    (display "T "))
                  (if (= (remainder n 3) 0) ; if n is divisible by 3, then display ICE
                      (begin
                        (T-Ice (- n 1))
                        (display "ICE "))
                      (begin
                        (T-Ice (- n 1))
                        (display n)
			(display " "))))))))


; C - returns the sum of all prime numbers from 1 to n
(define (Sumprimes n)
  (if (= n 1)
      0
      (if (isPrime n) ; if n is a prime number, then add it to the sum
          (+ n (Sumprimes (- n 1)))
          (Sumprimes (- n 1)))))

(define (isPrime n)
  (if (or (= n 1) (= n 2)) ; if n is 1 or 2, then it is a prime number
      #t
      (if (= (remainder n 2) 0) ; if n is divisible by 2, then it is not a prime number
          #f
          (isPrime_helper n 3))))

(define (isPrime_helper n i)
  (if (> i (sqrt n)) ; if i is greater than the square root of n, then it is a prime number
      #t
      (if (= (remainder n i) 0) ; if n is divisible by i, then it is not a prime number
          #f
          (isPrime_helper n (+ i 2)))))


; D - returns the result of a mathematical operation
(define (perform-op m n opt)
  (cond ((equal? opt '+) (+ m n)) 
        ((equal? opt '-) (- m n))
        ((equal? opt '*) (* m n))
        ((equal? opt '/) (/ m n))
        ((equal? opt '%) (modulo m n))
        (else (error "Invalid operator"))))


; E - return the distance between two points
(define (calc-distance x1 x2 y1 y2)
  (sqrt (+ (expt (abs (- x2 x1)) 2) 
           (expt (abs (- y2 y1)) 2))))


; F - returns the number of factors of a number
 (define (count-factors m n)
  (if (or (<= n 0) (<= m 0))
      (error "Please input positive integers") ; checks if m & n are less than or equal to 0
      (if (= m 1)
          1
          (if (= (modulo n m) 0) ; if m is a factor of n or n % m = 0, then proceed to count the factor
              (if (<= (modulo (/ n m) m)0) 
                  (+ 1(count-factors m(/ n m))) ;adds 1 and recursively call the function 
                  1) ; return 1 if the remainder > 0
              (display "None"))))) ; displays None if it is not a factor
