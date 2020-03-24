#if File.exists?("input")
#  $stdin = File.open("input")
#  $stdout = File.open("output","w")
#end
require 'set'
t = gets.to_i

def asdf(caphash,markerhash,capset,arr,i,n)

	while i<n
		thismarker = arr[i]
		capset.each do |thiscap|
			next if thiscap==thismarker
			#n-i-1 elements remain after this
=begin
			if(caphash[thiscap]-1 > (n-i-1-(markerhash[thiscap])))
				next
			end

			if(caphash[thismarker] > (n-i-1-(markerhash[thismarker]-1)))
				next
			end
=end

			wontwork = false
			updatedthismarker = false
			updatedthiscap = false

			capset.each do |x|
				if x==thismarker
					markerhash[x]-=1
					updatedthismarker = true
				end

				if x==thiscap
					caphash[x]-=1
					updatedthiscap = true
				end

				if caphash[x] > (n-i-1-(markerhash[x]))
					wontwork = true
					break
				end

			end

			if updatedthismarker
				markerhash[thismarker]+=1
			end

			if updatedthiscap
				caphash[thiscap]+=1
			end

			if wontwork
				next
			end

			caphash[thiscap]-=1
			if caphash[thiscap]==0
				capset.delete(thiscap)
			end
			markerhash[thismarker]-=1

			print thiscap
			print " "
=begin
			p caphash
			p markerhash
			p capset
			puts
=end

			i+=1
#			p i
#			asdf(caphash,markerhash,capset,arr,i+1,n)
			break
		end
	end
end



t.times do
	n = gets.to_i
	arr = gets.chomp.split(" ").map(&:to_i)

	caphash = Hash.new(0)
	markerhash = Hash.new(0)

	done = false
	arr.each do |x|
		caphash[x]+=1
		markerhash[x]+=1		
	end

	capset = Set.new
	caphash.each do |k,v|
		capset.add(k)
		if v>n/2
			done=true
		end
	end

	if done
		puts "No"
		next
	end

	puts "Yes"
	asdf(caphash, markerhash, capset, arr, 0, n)
	puts
end




