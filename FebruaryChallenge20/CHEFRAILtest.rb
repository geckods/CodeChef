t = 1#rand(5)+1
puts t
t.times do
	n = 100000#rand(50)+1
	m = 100000#rand(50)+1
	puts "#{n} #{m}"
	narr = (0..160000).to_a.sort{ rand() - 0.5 }[0..n-1]
	seenz=false;
	narr.each do |x|
		if x-80000==0 
			seenz=true
		end
		print x-80000
		print " "
	end
	puts
	marr = (0..160000).to_a.sort{ rand() - 0.5 }[0..m-1]
	gg = false;
	marr.each do |x|
		if seenz and x==80000
			gg = true
			next
		end
		print x-80000
		print " "
	end
	if gg
		puts 999
	else
		puts
	end

end