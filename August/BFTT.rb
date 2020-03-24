t = gets.to_i

arr = []
t.times {arr.push gets.to_i}

arr.each do |x|
  x+=1
  while x.to_s.count("3")<3
    x+=1
  end
  puts x
end
