t = gets.to_i

arr = []
t.times {arr.push gets.chomp.split(" ").map(&:to_i)}

arr.each do |z|
  k = z[2]
  p1 = z[0]
  p2 = z[1]

  if (((p1+p2)/k)%2 ==0)
    puts "CHEF"
  else
    puts "COOK"
  end
end
