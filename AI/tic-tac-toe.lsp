;;;Load in clisp and type (play-one-game);;;


;;creates an empty board (a list called board)
(defun make-board ()
  (list 'board 0 0 0 0 0 0 0 0 0))

;;if v is 1, return "0"
;;if v is 10 return "X"
;;otherwise return " "
(defun convert-to-letter (v)
  (cond ((equal v 1) "0")
        ((equal v 10) "X")
        (t " ")))

;;prints a row with parameters for the 3 slots
(defun print-row (x y z)
  (format t "~&  ~A | ~A | ~A"
    (convert-to-letter x)
    (convert-to-letter y)
    (convert-to-letter z)))

;;prints the whole board, has to call the print-row function 3 times
;;uses nth to decide which position in board list to put where
(defun print-board (board)
  (format t "~%")
  (print-row
   (nth 1 board) (nth 2 board) (nth 3 board))
  (format t "~& ___________")
  (print-row
    (nth 4 board) (nth 5 board) (nth 6 board))
  (format t "~& ___________")
  (print-row
   (nth 7 board) (nth 8 board) (nth 9 board))
  (format t "~%~%"))

;;modifies the board with a move, assumes legal move is given
;;player - who is making the move
;;pos - where the move is going
;;board - board in its current state
(defun make-move (player pos board)
  (setf (nth pos board) player)
  board)

;;values for each player's spot on the board
(setf *computer* 10)
(setf *opponent* 1)
(setf *p1* 10)
(setf *p2* 1)

;;defines triplets as a set of list indecies where each list is a
;;3-in-a-row line in the board list
(setf *triplets*
  '((1 2 3) (4 5 6) (7 8 9)
    (1 4 7) (2 5 8) (3 6 9)
    (1 5 9) (3 5 7)))

;;returns the sum for a given 3-in-a-row line
;;triplet - the line to be summed
(defun sum-triplet (board triplet)
  (+ (nth (first triplet) board)
     (nth (second triplet) board)
     (nth (third triplet) board)))

;;
(defun compute-sums (board)
  (mapcar #'(lambda (triplet)
              (sum-triplet board triplet))
    *triplets*))

;;
(defun winner-p (board)
  (let ((sums (compute-sums board)))
    (or (member (* 3 *computer*) sums)
        (member (* 3 *opponent*) sums))))

(defun p1-move (board)
  (let* ((pos (read-a-legal-move board))
         (new-board (make-move
                     *p1*
                     pos
                     board)))
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&X win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (p2-move new-board)))))

(defun p2-move (board)
  (let* ((pos (read-a-legal-move board))
         (new-board (make-move
                     *p2*
                     pos
                     board)))
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&0 win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (p1-move new-board)))))


(defun read-a-legal-move (board)
  (format t "~&Your move: ")
  (let ((pos (read)))
    (cond ((not (and (integerp pos)
                     (<= 1 pos 9)))
           (format t "~&Invalid input.")
           (read-a-legal-move board))
          ((not (zerop (nth pos board)))
           (format t
               "~&That space is already occupied.")
           (read-a-legal-move board))
          (t pos))))

(defun board-full-p (board)
  (not (member 0 board)))


;;The next 4 functions really should be 2, but that's a lot of work.
(defun opponent-move (board)
  (let* ((pos (read-a-legal-move board))
         (new-board (make-move
                     *opponent*
                     pos
                     board)))
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&You win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (computer-move new-board)))))

(defun hard-opponent-move (board)
  (let* ((pos (read-a-legal-move board))
         (new-board (make-move
                     *opponent*
                     pos
                     board)))
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&You win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (hard-computer-move new-board)))))

(defun computer-move (board)
  (let* ((best-move (random-move-strategy board))
         (pos (first best-move))
         (strategy (second best-move))
         (new-board (make-move
                     *computer* pos board)))
    (format t "~&My move: ~S" pos)
    (format t "~&My strategy: ~A~%" strategy)
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&I win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (opponent-move new-board)))))

(defun hard-computer-move (board)
  (let* ((best-move (choose-best-move board))
         (pos (first best-move))
         (strategy (second best-move))
         (new-board (make-move
                     *computer* pos board)))
    (format t "~&My move: ~S" pos)
    (format t "~&My strategy: ~A~%" strategy)
    (print-board new-board)
    (cond ((winner-p new-board)
           (format t "~&I win!"))
          ((board-full-p new-board)
           (format t "~&Tie game."))
          (t (hard-opponent-move new-board)))))

;;figures out the best option and does it
(defun choose-best-move (board)
  ;;if there is a smart move to be made, do it
  ;;otherwise just go randomly
  (if (smart-triple board)
      (smart-move-strategy board)
      (random-move-strategy board)
  )
)

;;maybe this isnt necessary
(defun smart-move-strategy(board)
  (list (pick-smart-position (smart-triple board) board) "smart move"))

;;recursively figures which of the 3 spots in the best line is free
(defun pick-smart-position(triple board)
  (cond ((eq (nth (first triple) board) 0) (first triple)) ((pick-smart-position (cdr triple) board))))

;;returns the best move "triplet" available
(defun smart-triple (board)
  (if (not (null (car(remove-if #'(lambda(triplet)(not (eq (sum-triplet board triplet) 20 ))) *triplets*))))
    (car(remove-if #'(lambda(triplet)(not (eq (sum-triplet board triplet) 20 ))) *triplets*))
    (car(remove-if #'(lambda(triplet)(not (eq (sum-triplet board triplet) 2 ))) *triplets*))
  )
)

;;
(defun random-move-strategy (board)
  (list (pick-random-empty-position board)
        "random move"))

;;
(defun pick-random-empty-position (board)
  (let ((pos (+ 1 (random 9))))
    (if (zerop (nth pos board))
        pos
      (pick-random-empty-position board))))

;;starts the whole thing!
(defun play-one-game ()
  (if (y-or-n-p "Would you like to play a friend? ")
    (p1-move (make-board))
    (who-first)
  )
)

;;for computer games, asks who should go first
(defun who-first ()

  (if (y-or-n-p "Would you like to go first?")

      (if (y-or-n-p "Would you play hard-mode? ")
          (hard-opponent-move (make-board))
          (opponent-move (make-board))
      )

      (if (y-or-n-p "Would you play hard-mode? ")
          (hard-computer-move (make-board))
          (computer-move (make-board))
      )
  )
)
