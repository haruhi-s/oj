(progn
  (def input (uiop:read-file-lines "day6.txt"))
  (setq input (np:asarray input))
  (def start (trivia:match (np:shape input)
               ((list m n)
                (iter (for i below m)
                  (iter inner (for j below n)
                    (when (eql #\^ (np:aref input i j))
                      (return (list i j)))))))))

;; (defun solve1 (start input)
;;   (macrolet ((at (pos) `(cl:aref input (aref ,pos 0 0) (aref ,pos 1 0))))
;;     (binds (((i . j) start)
;;             (pos (asarray `((,i) (,j))))
;;             (face (asarray '((-1) (0))))
;;             (mat (asarray '((0 1) (-1 0))))
;;             (turn () (setq face (matmul* mat face)))
;;             (next-place () (+ pos face))
;;             (next-char () (at (next-place)))
;;             (walk () (setq pos (next-place)))
;;             (paint () (setf (at pos) #\X)))
;;       (iter
;;         (unless (eq (at pos) #\X) (sum 1) (paint))
;;         (while (ignore-errors (next-char)))
;;         (when (eql (next-char) #\#) (turn) (next-iteration))
;;         (walk)))))

(defun solve2 (start input)
  (labels ((at (pos) (apply #'cl:aref input pos)))
    (binds ((h (make-hash-table :test 'equalp)))
      (iter outer (for m below 130)
        (print m)
        (iter inner (for n below 130)
          (when (or (eq #\# (aref input m n)) (eq #\^ (aref input m n))) (next-iteration))
          (clrhash h)
          (binds ((pos (copy-list start))
                  (face (list -1 0))
                  (turn () (setq face (match face
                                        ((list -1 0) (list 0 1))
                                        ((list 0 1) (list 1 0))
                                        ((list 1 0) (list 0 -1))
                                        ((list 0 -1) (list -1 0)))))
                  (next-place () (mapcar #'+ pos face))
                  (next-char () (at (next-place)))
                  (walk () (setq pos (next-place))))
            (iter
              (while (ignore-errors (next-char)))
              (when (or (equalp (list m n) (next-place)) (eql (next-char) #\#))
                (turn)
                (let ((k (list pos face)))
                  (when (gethash k h)
                    (in outer (sum 1))
                    (print "looped")
                    (return))
                  (setf (gethash k h) t))
                (next-iteration))
              (walk))))))))
