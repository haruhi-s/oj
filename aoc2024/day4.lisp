(def input (uiop:read-file-lines "day4.txt"))
(setq input (np:asarray input))

;; part 1
(def words '("XMAS" "SAMX"))
(def offsets '((0 1) (1 0) (1 1) (1 -1)))
(def starts '((0 0) (0 0) (0 0) (0 3)))
(def indices (mapcar
              (lambda (o s) (iter (for i below 4)
                              (with start = s)
                              (collect start)
                              (setq start (mapcar #'+ start o))))
              offsets starts))
(def bounds (iter (for inds in indices)
              (collecting
                (iter (for ij in inds)
                  (maximize (car ij) into imax)
                  (maximize (cadr ij) into jmax)
                  (finally (return (list imax jmax)))))))
(def ijss (iter outer
            (for i in indices)
            (for b in bounds)
            (collect (cart (iter (for x below (- 140 (car b))) (collect x))
                           (iter (for x below (- 140 (cadr b))) (collect x))))))

(def all-strings (iter outer (for ijs in ijss) (for inds in indices)
                   (iter (for start in ijs)
                     (in outer (collect (string-at input (mapcar (curry #'mapcar #'+ start) inds)))))))

;; part 2

(defun string-at (input indices)
  (iter (for ij in indices)
    (collect (apply #'np:aref input ij) :result-type string)))

(def words '("SSAMM" "SMASM" "MMASS" "MSAMS"))
(def indices '((0 0) (0 2) (1 1) (2 0) (2 2)))
(iter (for (word i j) in (cart words (iota 138) (iota 138)))
  (let ((indices (mapcar (curry #'mapcar #'+ (list i j)) indices)))
    (when (equal word (string-at input indices)) (sum 1))))

(defun solve2 (input)
  (labels ((string-at (input indices)
             (iter (for ij in indices)
               (collect (apply #'np:aref input ij) :result-type string))))
    (def words '("SSAMM" "SMASM" "MMASS" "MSAMS"))
    (def indices '((0 0) (0 2) (1 1) (2 0) (2 2)))
    (iter (for (word i j) in (cart words (iota 138) (iota 138)))
      (let ((indices (mapcar (curry #'mapcar #'+ (list i j)) indices)))
        (when (equal word (string-at input indices)) (sum 1))))))
