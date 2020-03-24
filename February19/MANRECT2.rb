t = gets.to_i

def myprint(x)
	puts x
	STDOUT.flush
end

def mycheck(x)
	if x<0
		exit
	end
	return x
end


t.times do
	myprint("Q 0 0")
	bl = mycheck(gets.to_i)
	myprint("Q 1000000000 0")
	br = mycheck(gets.to_i)
#	myprint("Q 0 1000000000")
#	tl = mycheck(gets.to_i)
	myprint("Q 1000000000 1000000000")
	tr = mycheck(gets.to_i)

	mid = (bl+1000000000-br)/2
	myprint("Q #{mid} 0")
	bot = mycheck(gets.to_i)

	left = bl-bot

	right = 1000000000-(br-bot)
	top = 2000000000-(tr+right)
	myprint("A #{left} #{bot} #{right} #{top}")
	response = gets.to_i
	if response!=1
		exit
	end
end
	
