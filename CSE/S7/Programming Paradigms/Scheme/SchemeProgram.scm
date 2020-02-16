
;To run: $ scheme --load SchemeProgram.scm
(display "\n--------------------------------------------------------------------------------\n")



(*)  ; 1
(+)  ; 0

(sqrt 16) ; 14

(define global_var 19)


; Functions

(define sum (lambda (x y) (+ x y)) )
(sum 6 7) ; 13

(define (sum x y)
	(+ x y)
)
(sum 8 9) ; 17


; Conditional Statements

(if (predicate) (#t statement)  (#f statement))

(if      (= x y)  (display "True") (display "False"))
(if (not (= x y)) (display "True") (display "False"))

(if (<  x y)      (display "True") (display "False"))
(if (>  x y)      (display "True") (display "False"))
(if (<= x y)      (display "True") (display "False"))
(if (>= x y)      (display "True") (display "False"))

(if (odd?  x)     (display "True") (display "False"))
(if (even? x)     (display "True") (display "False"))
(if (zero? x)     (display "True") (display "False"))
(if (symbol? x)   (display "True") (display "False"))
(if (boolean? x)  (display "True") (display "False"))



(cond ((predicate1) (statement1))
	  ((predicate2) (statement2))
	  ((predicate3) (statement3))
	  ((predicate4) (statement4))
	  (else (statement5))
)

(cond ((< x y)  (display "x is less than y"))
      ((> x y)  (display "x is greater than y"))
      (else     (display "x is equal to y"))
)


; Assignments and bindings

(let ( (a 3)
	   (b 4)
	   (sum (lambda (x y) (+ x y)))
	 )

	 (display (sum a b)) ; 7
)


(let ( (a 3) )
	 
	 (let ( (a 4)
	 	    (b a)
	 	    (c b)           ; [Error] Unbound variable: b
	 	  ; Note : the bindings defined here will only become active in the body of the 'let' construct !
	 	  )

	 	  (display a)   ; 4
	 	  (newline)
	 	  (display b)   ; 3
	 	  (newline)
	 	  (display c)   ; 3
	 )
)

(let ( (a 3) )
	 
	 (let* ( (a 4)
	 	     (b a)
	 	   )

	 	  (display a)   ; 4
	 	  (newline)
	 	  (display b)   ; 4
	 )
)

(let ( (a 3) )
	 
	 (let* ( (a 4)
	 	     (b a)
	 	     (c b)
	 	  )

	 	  (display a)   ; 4
	 	  (newline)
	 	  (display b)   ; 4
	 	  (newline)
	 	  (display c)   ; 4
	 )
)

(letrec ( (fact (lambda (n) (if (= n 1)
								1
			                    (* n (fact (- n 1)))
			                )
		        ) 
		  )
		)

		(display (fact 5))  ; 120
)



; Write your program here

(display (cons 'a 'b   ))   ; (a . b)
(display (cons 'a '(b) ))   ; (a b)

(display (car '(a b c d) )) ; a

(display (cdr '(a b c d) )) ; (b c d)


(display ('("\n") '(a b c) '("\n") ) ) 





(display "\n--------------------------------------------------------------------------------\n")


(define a 3)
(define b 4)
(display (+ a b))


(eq?    a b)  ; do a and b refer to the same object ?               shallow comparison
(eqv?   a b)  ; are a and b known to be semantically equivalent?    shallow comparison
(equal? a b)  ; do a and b refer to the same object ?

(display (eq? #t #t)         )
(display (eq? '(2) '(2))     )
(display (eq? 'foo 'foo)     )
(display (eq? '(a b) '(a b)) )


(let ((p '(a b))) (
  	(display (eq? p p))
  	(display (eq? "foo" "foo")) 
  	)
)




(memq   'c '(a b c d))  ; (c d)
(memv   'c '(a b c d))  ; (c d)
(member 'c '(a b c d))  ; (c d)

(memq   'f '(a b c d))  ; #f
(memv   'f '(a b c d))  ; #f
(member 'f '(a b c d))  ; #f


(memq 10 '(100 101 102))
(memv 10 '(100 101 102))


(memq   '(b) '(a (b) c (d)) ) ; #f
(memv   '(b) '(a (b) c (d)) ) ; #f
(member '(b) '(a (b) c (d)) ) ; ((b) c (d))

(memq   '(f) '(a (b) c (d)) ) ; #f
(memv   '(f) '(a (b) c (d)) ) ; #f
(member '(f) '(a (b) c (d)) ) ; #f


(do ( (i 1 (+ 2 i))
	  (n 10)
    )

    ((> i n))   ; exit condition ; if (condition == #t) then exit loop;
  
  	(display i)
  	(newline)
)

(do ( (i 0 )
      (n 10)
    )
	
	((> i n))
    
    (display i)
    (set! i (+ i 1))
    (newline)
)



(define del (delay (+ 3 4)))
(display del)
