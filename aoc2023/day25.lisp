(ql:quickload "graph")

(use-package :graph)

(defun parse (filename)
  (let ((g (make-instance 'graph:graph)))
    (iter (for line in (uiop:read-file-lines filename))
      (binds (((first rest) (str:split ": " line)))
        (iter (for r in (str:split " " rest))
          (graph:add-edge g (list (intern first) (intern r)) 1))))
    g))

(defun solve (g)
  (binds (((A . B) (nodes g))
          (A (list A))
          (cut (make-hash-table :test #'equal))
          (addedge (i j cut) (incf (gethash (list i j) cut 0)))
          (remedge (i j cut) (remhash (list i j) cut))
          (cutvalue () (iter (for (k v) in-hashtable cut) (sum v)))
          (max-connected (B cut) (iter (for node in B)
                                   (finding
                                    node maximizing
                                    (iter (for (k v) in-hashtable cut)
                                      (when (eq (cadr k) node) (sum v))))))
          (add (node)
            (deletef B node)
            (push node A)
            (iter (for i in (neighbors g node))
              (if (member i A)
                  (remedge i node cut)
                  (addedge node i cut)))))
    (iter (for nei in (neighbors g (car A)))
      (addedge (car A) nei cut))
    (iter
      (while (cdr B))
      (for node = (max-connected B cut))
      (add node)
      (for v = (cutvalue))
      (finding
       (list (let ((n (len A)) (g (len (nodes g)))) (* n (- g n))) v)
       minimizing v))))

(solve (parse "aoc2023/day25.in"))

