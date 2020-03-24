def update(arr,l,r,v)
	arr[l]+=v
	arr[r+1]-=v
end

t = gets.to_i
t.times do
	nk = gets.chomp.split(" ").map(&:to_i)
	n = nk[0]
	k = nk[1]

	updatearr = []
	n.times do
		updatearr.push gets.chomp.split(" ").map(&:to_i)
	end

	mainupdate = [0]*100000
	updatearr.each do |x|
		l = x[0]-1
		r = x[1]-1
		update(mainupdate,l,r,1)
	end

#	mainarr = []
	karr = []
	kplusonearr = []
	a = 0
	b = 0
	c = 0
	(0..99999).each do |i|
		a += mainupdate[i]
#		mainarr.push a
		b+=1 if(a==k)
		karr.push b
		c+=1 if(a==k+1)
		kplusonearr.push c
	end

	ans = 0

#	p mainupdate[0..10]

	updatearr.each do |x|
		l = x[0]-1
		r = x[1]-1

		if(l>0)
			minians = kplusonearr[r]-kplusonearr[l-1] + karr[l-1]+karr[-1]-karr[r]
		else
			minians =  kplusonearr[r] + karr[-1] - karr[r]
		end

#		puts "#{l} #{r} #{minians}"

		ans = minians if minians>ans
	end

	puts ans
end