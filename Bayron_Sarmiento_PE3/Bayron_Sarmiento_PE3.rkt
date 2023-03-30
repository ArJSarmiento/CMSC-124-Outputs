;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname Bayron_Sarmiento_PE3) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
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
  (if (< n 0)
      (error "Please input 0 or positive integers")
  (if (= n 0)
      1
      (* n (Factorial (- n 1))))))


; B - returns a set of numbers based on the T-Ice pattern from 1 to n
(define (T-Ice n)
  (if (< n 0)
      (begin
        (newline)
        (error "Please input numbers greater than 0"))
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
                        (display n))))))))


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
  (if (= m 1)
    1
    (let loop ((n n) (count 0))
    (cond ((= n 1) (if (= count 0) "None" count))
          ((= (remainder n m) 0) (loop (/ n m) (+ count 1)))
          (else (loop (- n 1) count))))))

;Count-factors function 
(define (countf m n)
  (if (or (<= n 0) (<= m 0))
      (error "Please input positive integers")
      (if (= m 1)
          1
          (if (= (modulo n m) 0) ;check if the the remainder of n to m is zero to proceed in getting its factor
              (if (<= (modulo (/ n m) m)0) 
                  (+ 1(countf m(/ n m))) ;adds 1 and recursively call the function 
                  1) ;returns 1 if the remainder is greater than 0
              (display "None"))))) ;displays None if there is no factors to be counted)
