#lang racket
;; Contract: area-of-ring : number number -> number

;; Purpose: to compute the area of a ring whose radius is
;; outer and whose hole has a radius of inner

;; Example: (area-of-ring 5 3) should produce 50.24

;; Definition: [refines the header]
(define (area-of-ring outer inner)
  (- (area-of-disk outer)
     (area-of-disk inner)))

;; Contract: area-of-disk : number -> number

;; Purpose: to compute the area of a circle whose radius
;; is r

;; Example: (area-of-disk 5) should produce 78.5
(define (area-of-disk r)
  (* 3.14 (* r r)))

;; Test:
(area-of-ring 5 3)
;; expected value
50.24