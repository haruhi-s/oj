(defun parse (file)
  (iter (for line in (uiop:read-file-lines file))
    (for (a b) = (str:split ": " line))
    (for numbers = (mapcar #'parse-integer (str:split " " b)))
    (collect (list (parse-integer a) numbers))))

(defun eqsolve1 (val list)
  (bind (((first . rest) list)
         ((:values quo rem) (floor val first)))
    (if rest
        (and (or (when (zerop rem) (eqsolve quo rest)) ;; *
                 (eqsolve (- val first) rest)) ;; +
             val)
        (if (eq val (car list))
            val nil))))

(defun eqsolve (val list)
  (bind (((first . rest) list)
         ((:values quo rem) (floor val first)))
    (if rest
        (and (bind (((:values quo10 rem10)
                     (floor val (expt 10 (1+ (floor (log first 10) 1))))))
               (or (when (eql first rem10) (eqsolve quo10 rest)) ;; concat
                   (or (when (zerop rem) (eqsolve quo rest)) ;; *
                       (eqsolve (- val first) rest)))) ;; +
             val)
        (if (eq val (car list))
            val nil))))

(defun solve (eqns)
  (iter (for (val list) in eqns)
    (sum (or (eqsolve val (reverse list)) 0))))
