(begin
    (display "Programming Exercise 4")
    (newline)
    (display "This program is a collection of functions that perform various tasks with lists using the scheme language")
    (newline)
    (display "Sean Gabriel Bayron")
    (newline)
    (display "Student Number: 2021-04354")
    (newline)
    (display "Arnel Jan Sarmiento")
    (newline)
    (display "Student Number: 2021-05094")
    (newline)
    (display "Date: 2023-4-14")
    (newline)
)

; A - recursive function that sums up all the numbers in a list, including
; those in sublists.  The list may contain any number of sublists, which
; may contain any number of sublists, and so on.
(define (my-sums lis)
  (sum-helper lis 0))

(define (sum-helper lst acc)
  (cond
    ((null? lst) acc)
    ((number? (car lst)) (sum-helper (cdr lst) (+ acc (car lst))))
    (else (sum-helper (cdr lst) (+ acc (my-sums (car lst)))))))


; B - recursive function that returns a reversed version of a list with helper function.
(define (my-reverse1 lis)
  (reverse-helper lis '()))

(define (reverse-helper lis1 lis2)
    (if (null? lis1)
    lis2
    (reverse-helper (cdr lis1) (cons (car lis1) lis2))))


; C - recursive function that returns a reversed version of a list without helper function. 
(define (my-reverse2 lis)
  (if (null? lis)
      '()
      (if (not (list? lis))
          (error "Input is not a list")
          (let loop ((lis lis) (acc '()))
            (if (null? lis)
                acc
                (loop (cdr lis) (cons (car lis) acc)))))))
