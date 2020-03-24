require 'set'

if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i
t.times do
	n = gets.to_i
	myset = gets.chomp.each_char.to_a

	(n-1).times do
		set = gets.chomp.each_char.to_a
		myset = myset&set
	end

	puts myset.uniq.size
end