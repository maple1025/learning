#lang racket

(define start 1)

(define (factorial n)
  (fact-iter start 1 n))

(define (fact-iter product counter max-count)
  (if (> counter max-count)
      product
      (fact-iter (* counter product)
                 (+ counter 1)
                 max-count)))