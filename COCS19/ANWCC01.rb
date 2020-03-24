if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i
t.times do
  n = gets.to_i
  puts 1+(Math.log(n/2)/Math.log(2)).ceil
end