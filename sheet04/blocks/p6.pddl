(define (problem BLOCKS-5-0)
(:domain BLOCKS)
(:objects B E A C D )
(:INIT (CLEAR D) (CLEAR C) (ONTABLE D) (ONTABLE A) (ON C E) (ON E B) (ON B A)
 (HANDEMPTY))
(:goal (AND (ON A E) (ON E B) (ON B D) (ON D C)))
)