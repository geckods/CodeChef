if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i
t.times do
	str = gets.chomp.split("=")#split(%r{[=\+-]})
	part = eval(str[0])
	if part==str[1].to_i
		puts "Valid"
	else
		puts "Invalid"
	end
end
