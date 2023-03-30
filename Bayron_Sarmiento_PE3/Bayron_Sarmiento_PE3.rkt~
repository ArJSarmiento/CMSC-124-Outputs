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
  (if (= n 0)
      1
      (* n (Factorial (- n 1)))))


; B - returns a set of numbers based on the T-Ice pattern from 1 to n
(define (T-Ice n)
  (if (= n 1)
      (display "1")
      (if (and (= (remainder n 2) 0) (= (remainder n 3) 0))
          (begin
            (T-Ice (- n 1))
            (newline)
            (display "T-ICE"))
          (if (= (remainder n 2) 0)
              (begin
                (T-Ice (- n 1))
                (newline)
                (display "T"))
              (if (= (remainder n 3) 0)
                  (begin
                    (T-Ice (- n 1))
                    (newline)
                    (display "ICE"))
                  (begin
                    (T-Ice (- n 1))
                    (newline)
                    (display n)))))))


; C - returns the sum of all prime numbers from 1 to n
(define (isPrime n)
  (if (or (= n 1) (= n 2))
      #t
      (if (= (remainder n 2) 0)
          #f
          (isPrime_helper n 3))))

(define (isPrime_helper n i)
  (if (> i (sqrt n))
      #t
      (if (= (remainder n i) 0)
          #f
          (isPrime_helper n (+ i 2)))))

(define (Sumprimes n)
  (if (= n 1)
      0
      (if (isPrime n)
          (+ n (Sumprimes (- n 1)))
          (Sumprimes (- n 1)))))


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
  (if (= n 1)
      0
      (if (= (remainder n m) 0)
          (+ 1 (count-factors m (/ n m)))
          (count-factors m (- n 1)))))