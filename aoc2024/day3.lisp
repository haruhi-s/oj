(ql:quickload "cl-ppcre")
(setf (symbol-function 'all-matches) #'cl-ppcre:all-matches-as-strings)

(iter (for s in (~ "day3.txt" (uiop:read-file-lines)
                   (mapcar (curry #'all-matches "mul\\([0-9]{1,3},[0-9]{1,3}\\)"))
                   (flatten)))
  (~ s (all-matches "\\d{1,3}") (mapcar #'parse-integer) (apply #'*) (sum)))

(iter (for s in (~ "day3.txt" (uiop:read-file-lines)
                   (mapcar (curry #'all-matches "do\\(\\)|don't\\(\\)|mul\\([0-9]{1,3},[0-9]{1,3}\\)"))
                   (flatten)))
  (with do = t)
  (when (equal s "do()") (setq do t) (next-iteration))
  (when (equal s "don't()") (setq do nil) (next-iteration))
  (when do (~ s (all-matches "\\d{1,3}") (mapcar #'parse-integer) (apply #'*) (sum))))
