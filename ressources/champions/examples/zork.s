.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:coucou, %1
		and r1, %0, r1

coucou:	live %1
zjmp %:live
