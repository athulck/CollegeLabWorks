
(display "\n--------------------------------------------------------------------------------\n")


(define X 2)
(define Y 2)

(display (eq? X Y))     ;#t
(display (eqv? X Y))    ;#t
(display (equal? X Y))  ;#t

(newline)

(define X 2)
(define Y 3)

(display (eq? X Y))     ;#f
(display (eqv? X Y))    ;#f
(display (equal? X Y))  ;#f

(newline)


(define X '(a b))
(define Y '(a b))

(display (eq? X Y))     ;#f
(display (eqv? X Y))    ;#f
(display (equal? X Y))  ;#t

(newline)

(define X '(1 2))
(define Y '(2 2))

(display (eq? X Y))     ;#f
(display (eqv? X Y))    ;#f
(display (equal? X Y))  ;#f

(newline)

(define X '(a b))
(define Y X)

(display (eq? X Y))     ;#t
(display (eqv? X Y))    ;#t
(display (equal? X Y))  ;#t


(display "\n--------------------------------------------------------------------------------\n")
