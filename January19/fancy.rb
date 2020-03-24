if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
n.times do
	asd = " " + gets.chomp + " "
	if (/[^A-Za-z]not[^A-Za-z]/ =~ asd) == nil
		puts "regularly fancy"
	else
		puts "Real Fancy"
	end
end