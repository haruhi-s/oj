(progn
  (def input (uiop:read-file-lines "day5.in"))
  (def input (s:split-sequence-if (curry #'equal "") input))
  (def rules (car input))
  (def lists (cadr input))

  (def rules (mapcar (lambda (i) (mapcar #'parse-integer (str:split " " i))) rules))
  (def lists (mapcar (lambda (i) (mapcar #'parse-integer (str:split " " i))) lists)))

(iter outer (for list in lists)
  (iter (for i on list)
    (if (null (cdr i)) (next-iteration))
    (if (some (lambda (tail) (null (member (list (car i) tail) rules :test 'equal))) (cdr i))
        (return))
    (finally (in outer (sum (nth (floor (length list) 2) list))))))

(defun solve2 (rules lists)
  (iter (for list in (copy-tree lists))
    (for sorted = nil)
    (iter out (for i on list)
      (iter (for j on (cdr i))
        (when (member (list (car j) (car i)) rules :test 'equal)
          (setq sorted t)
          (rotatef (car i) (car j)))))
    (when sorted (sum (nth (floor (length list) 2) list)))))

;; kchan sol'n

(defun parse (file)
  (bind ((lines (uiop:read-file-lines file))
          ((rules sequences)
           (serapeum:split-sequence "" lines :test 'equal)))
    (values
     (mapcar (lambda (r) (mapcar #'parse-integer (str:split "|" r)))
             rules)
     (mapcar
      (lambda (r) (map 'vector #'parse-integer (str:split "," r)))
      sequences))))

(defun solve2 (rules sequences)
  (declare (optimize (safety 0))
           (type (simple-array bit (100 100)) rules))
  (iter (for s in sequences)
    (for keep = nil)
    (for ss = (stable-sort s
                           (lambda (a b)
                             (when (eq (aref rules a b) 1)
                               (setq keep t)))))
    (when keep
      (sum (middle ss)))))

(bind (((:values rules sequences) (parse "~/oj/aoc2024/day5.txt"))
        (r (make-array (list 100 100) :element-type 'bit)))
  (iter (for (a b) in rules)
    (setf (aref r a b) 1))
  (time (iter (repeat 1000) (sum (solve2 r (mapcar #'copy-seq sequences))))))
