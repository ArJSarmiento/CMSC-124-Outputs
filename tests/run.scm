(define (factorial n)
  (if (= n 0)
      1
      (* n (factorial (- n 1)))))

(define (main)
  (display "Enter a number: ")
  (newline)
  (let ((num (read)))
    (display (factorial num))))

(main)
