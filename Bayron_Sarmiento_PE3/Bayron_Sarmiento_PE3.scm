(define (factorial n)
  (if (= n 0)
      1
      (* n (factorial (- n 1)))))


(define (t-ice n)
  (do ((i 1 (+ i 1)))
      ((> i n))
    (cond ((and (= (modulo i 2) 0) (= (modulo i 3) 0))
           (display "T-ICE "))
          ((= (modulo i 2) 0)
           (display "T "))
          ((= (modulo i 3) 0)
           (display "ICE "))
          (else
           (display i)))
    (display " ")))

(define (sumprimes n)
  (define (is-prime x)
    (and (> x 1)
         (let loop ((i 2))
           (or (= i x)
               (and (not (= (modulo x i) 0))
                    (loop (+ i 1)))))))
  (let loop ((i 2)
             (sum 0))
    (if (> i n)
        sum
        (if (is-prime i)
            (loop (+ i 1) (+ sum i))
            (loop (+ i 1) sum)))))

(define (perform-op m n opt)
  (cond ((eq? opt '+) (+ m n))
        ((eq? opt '-) (- m n))
        ((eq? opt '*) (* m n))
        ((eq? opt '/) (/ m n))
        ((eq? opt '%) (modulo m n))
        (else (error "Invalid operator"))))

(define (calc-distance x1 x2 y1 y2)
  (sqrt (+ (square (- x2 x1))
           (square (- y2 y1)))))


(define (count-factors m n)
  (define (helper x)
    (if (= (modulo n x) 0)
        (+ 1 (helper (/ n x)))
        0))
  (let ((count (helper m)))
    (if (= count 0)
        (display "None")
        count)))